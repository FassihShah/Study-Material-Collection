using HospitalEntities;
using HospitalManagementDAL;

namespace HospitalManagementConsoleApp
{
    public class AppointmentManagement
    {
        AppointmentDataAccess appointmentData = new AppointmentDataAccess();
        PatientDataAccess patientData = new PatientDataAccess();
        DoctorDataAccess doctorData = new DoctorDataAccess();
        PatientManagement patients = new PatientManagement();
        DoctorManagement doctors = new DoctorManagement();
        InputValidation validator = new InputValidation();
        public void addAppointment()
        {
            patients.viewAllPatients();
            Console.WriteLine("");
            doctors.viewAllDoctors();
            Appointment newAppointment = new Appointment();
            Console.Write("Enter Patient ID: ");
            newAppointment.PatientId = int.Parse(Console.ReadLine());
            while(!patientData.isPatientInDatabase(newAppointment.PatientId))
            {
                Console.Write("No patient found with this id. Enter a valid patient id: ");
                newAppointment.PatientId = int.Parse(Console.ReadLine());
            }
            Console.Write("Enter Doctor ID: ");
            newAppointment.DoctorId = int.Parse(Console.ReadLine());
            while (!doctorData.isDoctorInDatabase(newAppointment.DoctorId))
            {
                Console.Write("No Doctor found with this id. Enter a valid doctor id: ");
                newAppointment.DoctorId = int.Parse(Console.ReadLine());
            }
            Console.Write("Enter Appointment Date (yyyy-MM-dd HH:mm): ");
            DateTime date = DateTime.Parse(Console.ReadLine());
            while (!validator.isValidAppointmentDate(newAppointment.DoctorId,date))
            {
                Console.Write("Invalid Date! Enter a valid date (yyyy-MM-dd HH:mm): ");
                date = DateTime.Parse(Console.ReadLine());
            }
            newAppointment.AppointmentDate = date;
            appointmentData.insertAppointment(newAppointment);
            Console.WriteLine("Appointment added successfully!");
        }
        public void updateAppointment()
        {
            Console.Write("Enter Appointment ID to update: ");
            int id = int.Parse(Console.ReadLine());
            Appointment appointment = appointmentData.getAppointment(id);
            if (appointment == null)
            {
                Console.WriteLine("Appointment not found.");
                return;
            }
            Console.Write($"Current Patient ID: {appointment.PatientId}. Enter new Patient ID: ");
            int newPatientId = int.Parse(Console.ReadLine());
            while (!patientData.isPatientInDatabase(newPatientId))
            {
                Console.Write("No patient found with this id. Enter a valid patient id: ");
                newPatientId = int.Parse(Console.ReadLine());
            }
            appointment.PatientId = newPatientId;
            Console.Write($"Current Doctor ID: {appointment.DoctorId}. Enter new Doctor ID: ");
            int  newDoctorId = int.Parse(Console.ReadLine());
            while (!doctorData.isDoctorInDatabase(newDoctorId))
            {
                Console.Write("No Doctor found with this id. Enter a valid doctor id: ");
                newDoctorId = int.Parse(Console.ReadLine());
            }
            appointment.DoctorId = newDoctorId;
            Console.Write($"Current Appointment Date: {appointment.AppointmentDate}. Enter new Date (yyyy-MM-dd HH:mm): ");
            DateTime newDate = DateTime.Parse(Console.ReadLine());
            while (!validator.isValidAppointmentDate(appointment.DoctorId,newDate))
            {
                Console.Write("Appointment Date is conflicting or invalid. Enter a valid appointment date (yyyy-MM-dd HH:mm): ");
                newDate = DateTime.Parse(Console.ReadLine());
            }
            appointment.AppointmentDate = newDate;
            appointmentData.updateAppointmentInDatabase(appointment);
            Console.WriteLine("Appointment updated successfully!");
        }
        public void deleteAppointment()
        {
            Console.Write("Enter Appointment ID to delete: ");
            int id = int.Parse(Console.ReadLine());
            if (!appointmentData.isAppointmentInDatabase(id))
            {
                Console.WriteLine("Appointment not found.");
                return;
            }
            appointmentData.deleteAppointmentFromDatabase(id);
            Console.WriteLine("Appointment deleted successfully!");
        }
        public void searchAppointments()
        {
            Console.Write("Enter patient id to search appointments: ");
            int patientId = int.Parse(Console.ReadLine());
            if (!patientData.isPatientInDatabase(patientId))
            {
                Console.WriteLine("Patient not found!");
                return;
            }
            Console.Write("Enter doctor id to search appointments: ");
            int doctorId = int.Parse(Console.ReadLine());
            if (!doctorData.isDoctorInDatabase(doctorId))
            {
                Console.WriteLine("Doctor not found!");
                return;
            }
            List<Appointment> foundAppointments = appointmentData.searchAppointmentInDatabase(doctorId,patientId);
            if (foundAppointments.Count > 0)
            {
                int i = 0;
                Console.WriteLine("Appointments found:");
                while (i < foundAppointments.Count)
                {
                    Console.WriteLine($"ID: {foundAppointments[i].AppointmentId}, Patient ID: {foundAppointments[i].PatientId}, Doctor ID: {foundAppointments[i].DoctorId}, Date: {foundAppointments[i].AppointmentDate}");
                    i++;
                }
            }
            else
            {
                Console.WriteLine("No appointments found.");
            }
        }
        public void viewAllAppointments()
        {
            List<Appointment> foundAppointments = appointmentData.getAllAppointmentsFromDatabase();
            if (foundAppointments.Count > 0)
            {
                int i = 0;
                Console.WriteLine("Appointments:");
                while (i < foundAppointments.Count)
                {
                    Console.WriteLine($"ID: {foundAppointments[i].AppointmentId}, Patient ID: {foundAppointments[i].PatientId}, Doctor ID: {foundAppointments[i].DoctorId}, Date: {foundAppointments[i].AppointmentDate}");
                    i++;
                }
            }
            else
            {
                Console.WriteLine("No appointments found.");
            }
        }
    }

}
