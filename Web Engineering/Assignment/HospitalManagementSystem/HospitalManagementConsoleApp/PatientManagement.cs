
using HospitalEntities;
using HospitalManagementDAL;

namespace HospitalManagementConsoleApp
{
    public class PatientManagement
    {
        PatientDataAccess patientData = new PatientDataAccess();
        InputValidation validator = new InputValidation();
        public void addPatient()
        {
            Patient newPatient = new Patient();
            Console.Write("Enter Name: ");
            newPatient.Name = Console.ReadLine();
            while (!validator.isValidName(newPatient.Name))
            {
                Console.Write("Invalid Name! Enter a valid Name: ");
                newPatient.Name = Console.ReadLine();
            }
            Console.Write("Enter Email: ");
            newPatient.Email = Console.ReadLine();
            while(!validator.isValidEmail(newPatient.Email))
            {
                Console.Write("Invalid Email! Enter a Valid Email: ");
                newPatient.Email = Console.ReadLine();
            }
            Console.Write("Enter Disease: ");
            newPatient.Disease = Console.ReadLine();
            while (!validator.isValidDisease(newPatient.Disease))
            {
                Console.Write("Invalid Disease! Enter a valid Disease: ");
                newPatient.Disease = Console.ReadLine();
            }
            patientData.insertPatient(newPatient);
            Console.WriteLine("Patient added successfully!");
        }
        public void updatePatient()
        {
            Console.Write("Enter Patient ID to update: ");
            int id = int.Parse(Console.ReadLine());
            Patient p = patientData.getPatient(id);    
            if (p == null )
            {
                Console.WriteLine("Patient not found.");
                return;
            }
            Console.Write($"Current Name: {p.Name}. Enter new Name (or press Enter to keep the same): ");
            string newName = Console.ReadLine();
            if (validator.isValidName(newName))
            {
                p.Name = newName;
            }
            Console.Write($"Current Email: {p.Email}. Enter new Email (or press Enter to keep the same): ");
            string newEmail = Console.ReadLine();
            if (validator.isValidEmail(newEmail))
            {
                p.Email = newEmail;
            }
            Console.Write($"Current Disease: {p.Disease}. Enter new Disease (or press Enter to keep the same): ");
            string newDisease = Console.ReadLine();
            if (validator.isValidDisease(newDisease))
            {
                p.Disease = newDisease;
            }
            patientData.updatePatientInDatabase(p);
            Console.WriteLine("Patient updated successfully!");
        }
        public void deletePatient()
        {
            Console.Write("Enter Patient ID to delete: ");
            int id = int.Parse(Console.ReadLine());
            if (!patientData.isPatientInDatabase(id))
            {
                Console.WriteLine("Patient not found.");
                return;
            }
            patientData.deletePatientFromDatabase(id);
            Console.WriteLine("Patient deleted successfully!");
        }
        public void searchPatients()
        {
            Console.Write("Enter the name of the patient to search: ");
            string name = Console.ReadLine();
            if(!validator.isValidName(name))
            {
                Console.WriteLine("Invalid Name!");
                return;
            }
            List<Patient> foundPatients = patientData.searchPatientsInDatabase(name);
            if (foundPatients.Count > 0)
            {
                int i = 0;
                Console.WriteLine("Patients found:");
                while (i < foundPatients.Count)
                {
                    Console.WriteLine($"ID: {foundPatients[i].PatientId}, Name: {foundPatients[i].Name}, Email: {foundPatients[i].Email}, Disease: {foundPatients[i].Disease}");
                    i++;
                }
            }
            else
            {
                Console.WriteLine("No patients found with that name.");
            }
        }
        public void viewAllPatients()
        {
            List<Patient> foundPatients = patientData.getAllPatientsFromDatabase();
            if (foundPatients.Count > 0)
            {
                int i = 0;
                Console.WriteLine("Patients:");
                while (i < foundPatients.Count)
                {
                    Console.WriteLine($"ID: {foundPatients[i].PatientId}, Name: {foundPatients[i].Name}, Email: {foundPatients[i].Email}, Disease: {foundPatients[i].Disease}");
                    i++;
                }
            }
            else
            {
                Console.WriteLine("No patients found.");
            }
        }
    }   
}
