using HospitalEntities;
using HospitalManagementDAL;

namespace HospitalManagementConsoleApp
{
    public class Menu
    {
        PatientManagement patients = new PatientManagement();
        DoctorManagement doctors = new DoctorManagement();
        AppointmentManagement appointments = new AppointmentManagement();
        HistoryLogger history = new HistoryLogger();
        public void displayMainMenu()
        {
            Console.WriteLine("\n\nWelcome to the Hospital Management System");
            Console.WriteLine("1. Manage Patients");
            Console.WriteLine("2. Manage Doctors");
            Console.WriteLine("3. Manage Appointments");
            Console.WriteLine("4. View History of Deleted Records");
            Console.WriteLine("5. Exit");
            Console.Write("Please select an option: ");
        }
        public void handleUserSelection(int selection)
        {
            switch (selection)
            {
                case 1:
                    managePatients();
                    break;
                case 2:
                    manageDoctors();
                    break;
                case 3:
                    manageAppointments();
                    break;
                case 4:
                    viewHistory();
                    break;
                case 5:
                    exitApplication();
                    return;
                default:
                    Console.WriteLine("Invalid selection. Please try again.");
                    break;
            }
        }
        void managePatients()
        {
            while (true)
            {
                Console.WriteLine("\nManaging Patients...");
                Console.WriteLine("1. Add Patient");
                Console.WriteLine("2. Update Patient");
                Console.WriteLine("3. Delete Patient");
                Console.WriteLine("4. Search for Patients by Name");
                Console.WriteLine("5. View All Patients");
                Console.WriteLine("6. Back to Main Menu");
                Console.Write("Select an option: ");
                int selection = int.Parse(Console.ReadLine());
                switch (selection)
                {
                    case 1:
                        patients.addPatient();
                        break;
                    case 2:
                        patients.updatePatient();
                        break;
                    case 3:
                        patients.deletePatient();
                        break;
                    case 4:
                        patients.searchPatients();
                        break;
                    case 5:
                        patients.viewAllPatients();
                        break;
                    case 6:
                        return;
                    default:
                        Console.WriteLine("Invalid selection. Please try again.");
                        break;
                }
            }
        }
        void manageDoctors()
        {
            while (true)
            {
                Console.WriteLine("\nManaging Doctors...");
                Console.WriteLine("1. Add Doctor");
                Console.WriteLine("2. Update Doctor");
                Console.WriteLine("3. Delete Doctor");
                Console.WriteLine("4. Search for Doctors by Name");
                Console.WriteLine("5. View All Doctors");
                Console.WriteLine("6. Back to Main Menu");
                Console.Write("Select an option: ");
                int selection = int.Parse(Console.ReadLine());
                switch (selection)
                {
                    case 1:
                        doctors.addDoctor();
                        break;
                    case 2:
                        doctors.updateDoctor();
                        break;
                    case 3:
                        doctors.deleteDoctor();
                        break;
                    case 4:
                        doctors.searchDoctors();
                        break;
                    case 5:
                        doctors.viewAllDoctors();
                        break;
                    case 6:
                        return;
                    default:
                        Console.WriteLine("Invalid selection. Please try again.");
                        break;
                }
            }
        }

        void manageAppointments()
        {
            while(true)
            {
                Console.WriteLine("\nManaging Appointments...");
                Console.WriteLine("1. Add Appointment");
                Console.WriteLine("2. Update Appointment");
                Console.WriteLine("3. Delete Appointment");
                Console.WriteLine("4. Search for Appointments by doctor and patient");
                Console.WriteLine("5. View All Appointments");
                Console.WriteLine("6. Back to Main Menu");
                Console.Write("Select an option: ");

                int selection = int.Parse(Console.ReadLine());

                switch (selection)
                {
                    case 1:
                        appointments.addAppointment();
                        break;
                    case 2:
                        appointments.updateAppointment();
                        break;
                    case 3:
                        appointments.deleteAppointment();
                        break;
                    case 4:
                        appointments.searchAppointments();
                        break;
                    case 5:
                        appointments.viewAllAppointments();
                        break;
                    case 6:
                        return;
                    default:
                        Console.WriteLine("Invalid selection. Please try again.");
                        break;
                }
            }
        }
        void viewHistory()
        {
            Console.WriteLine("\n1. History of Patients");
            Console.WriteLine("2. History of Doctors");
            Console.WriteLine("3. History of Appointments");
            Console.WriteLine("4. Back");
            int selection = int.Parse(Console.ReadLine());

            switch (selection)
            {
                case 1:
                    history.viewPatientsHistory();
                    break;
                case 2:
                    history.viewDoctorsHistory();
                    break;
                case 3:
                    history.viewAppointmentsHistory();
                    break;
                case 4:
                    return;
                default:
                    Console.WriteLine("Invalid selection. Please try again.");
                    break;
            }
        }
        void exitApplication()
        {
            Console.WriteLine("Exiting the application. Goodbye!");
        }
    }
}
