using HospitalEntities;
using HospitalManagementDAL;

namespace HospitalManagementConsoleApp
{
    public class DoctorManagement
    {
        DoctorDataAccess doctorData = new DoctorDataAccess();
        InputValidation validator = new InputValidation();
        public void addDoctor()
        {
            Doctor newDoctor = new Doctor();
            Console.Write("Enter Name: ");
            newDoctor.Name = Console.ReadLine();
            while (!validator.isValidName(newDoctor.Name))
            {
                Console.Write("Invalid Name! Enter a valid Name: ");
                newDoctor.Name = Console.ReadLine();
            }
            Console.Write("Enter Specialization: ");
            newDoctor.Specialization = Console.ReadLine();
            while (!validator.isValidSpecialization(newDoctor.Specialization))
            {
                Console.Write("Invalid Specialization! Enter a valid Specialization: ");
                newDoctor.Specialization = Console.ReadLine();
            }
            doctorData.insertDoctor(newDoctor);
            Console.WriteLine("Doctor added successfully!");
        }
        public void updateDoctor()
        {
            Console.Write("Enter Doctor ID to update: ");
            int id = int.Parse(Console.ReadLine());
            Doctor d = doctorData.getDoctor(id);
            if (d == null)
            {
                Console.WriteLine("Doctor not found.");
                return;
            }
            Console.Write($"Current Name: {d.Name}. Enter new Name (or press Enter to keep the same): ");
            string newName = Console.ReadLine();
            if (validator.isValidName(newName))
            {
                d.Name = newName;
            }
            Console.Write($"Current Specialization: {d.Specialization}. Enter new Specialization (or press Enter to keep the same): ");
            string newSpecialization = Console.ReadLine();
            if (validator.isValidSpecialization(newSpecialization))
            {
                d.Specialization = newSpecialization;
            }
            doctorData.updateDoctorInDatabase(d);
            Console.WriteLine("Doctor updated successfully!");
        }
        public void deleteDoctor()
        {
            Console.Write("Enter Doctor ID to delete: ");
            int id = int.Parse(Console.ReadLine());
            if (!doctorData.isDoctorInDatabase(id))
            {
                Console.WriteLine("Doctor not found.");
                return;
            }
            doctorData.deleteDoctorFromDatabase(id);
            Console.WriteLine("Doctor deleted successfully!");
        }
        public void searchDoctors()
        {
            Console.Write("Enter the name of the doctor to search: ");
            string name = Console.ReadLine();
            if (!validator.isValidName(name))
            {
                Console.WriteLine("Invalid Name!");
                return;
            }
            List<Doctor> foundDoctors = doctorData.searchDoctorsInDatabase(name);
            if (foundDoctors.Count > 0)
            {
                int i = 0;
                Console.WriteLine("Doctors found:");
                while (i < foundDoctors.Count)
                {
                    Console.WriteLine($"ID: {foundDoctors[i].DoctorId}, Name: {foundDoctors[i].Name}, Specialization: {foundDoctors[i].Specialization}");
                    i++;
                }
            }
            else
            {
                Console.WriteLine("No doctors found with that name.");
            }
        }
        public void viewAllDoctors()
        {
            List<Doctor> foundDoctors = doctorData.getAllDoctorsFromDatabase();
            if (foundDoctors.Count > 0)
            {
                int i = 0;
                Console.WriteLine("Doctors:");
                while (i < foundDoctors.Count)
                {
                    Console.WriteLine($"ID: {foundDoctors[i].DoctorId}, Name: {foundDoctors[i].Name}, Specialization: {foundDoctors[i].Specialization}");
                    i++;
                }
            }
            else
            {
                Console.WriteLine("No doctors found.");
            }
        }
    }

}
