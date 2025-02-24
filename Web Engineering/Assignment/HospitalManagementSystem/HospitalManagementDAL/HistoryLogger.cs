using HospitalEntities;
using Microsoft.Data.SqlClient;
using System.Text.Json;
namespace HospitalManagementDAL
{
    internal class DeletedPatientRecord      /// Patient with deleted Timestamp
    {
        public Patient Patient { get; set; }
        public DateTime DeletionTimestamp { get; set; }
    }
    internal class DeletedDoctorRecord      /// Doctor with deleted Timestamp
    {
        public Doctor Doctor { get; set; }
        public DateTime DeletionTimestamp { get; set; }
    }
    internal class DeletedAppointmentRecord    /// Appointment with deleted Timestamp
    {
        public Appointment Appointment { get; set; }
        public DateTime DeletionTimestamp { get; set; }
    }
    public class HistoryLogger
    {
        public static void addPatientToHistory(int id)
        {
            using StreamWriter sw = new StreamWriter("DeletedPatients.txt", append: true);
            string connectionString = "Data Source=(localdb)\\ProjectModels;Initial Catalog=HospitalManagementSystem;Integrated Security=True;";
            using SqlConnection connection = new SqlConnection(connectionString);
            try
            {
                Patient p = new Patient();
                string find = "select * from Patients where PatientId = @PatientId";
                using SqlCommand findCommand = new SqlCommand(find, connection);
                findCommand.Parameters.AddWithValue("@PatientId", id);
                connection.Open();
                using SqlDataReader reader = findCommand.ExecuteReader();
                while (reader.Read())
                {
                    p.PatientId = reader.GetInt32(0);
                    p.Name = reader.GetString(1);
                    p.Email = reader.GetString(2);
                    p.Disease = reader.GetString(3);
                }
                DeletedPatientRecord record = new();
                record.Patient = p;
                record.DeletionTimestamp = DateTime.Now;
                string jsonRecord = JsonSerializer.Serialize(record);
                sw.WriteLine(jsonRecord);
            }
            catch (Exception ex)
            {
                Console.WriteLine("!!!An error occurred while adding history of deleted Patient!!!");
            }
        }
        public static void addDoctorToHistory(int id)
        {
            using StreamWriter sw = new StreamWriter("DeletedDoctors.txt", append: true);
            string connectionString = "Data Source=(localdb)\\ProjectModels;Initial Catalog=HospitalManagementSystem;Integrated Security=True;";
            using SqlConnection connection = new SqlConnection(connectionString);
            try
            {
                Doctor d = new Doctor();
                string find = "select * from Doctors where DoctorId = @DoctorId";
                using SqlCommand findCommand = new SqlCommand(find, connection);
                findCommand.Parameters.AddWithValue("@DoctorId", id);
                connection.Open();
                using SqlDataReader reader = findCommand.ExecuteReader();
                while (reader.Read())
                {
                    d.DoctorId = reader.GetInt32(0);
                    d.Name = reader.GetString(1);
                    d.Specialization = reader.GetString(2);
                }
                DeletedDoctorRecord record = new();
                record.Doctor = d;
                record.DeletionTimestamp = DateTime.Now;
                string jsonRecord = JsonSerializer.Serialize(record);
                sw.WriteLine(jsonRecord);
            }
            catch (Exception ex)
            {
                Console.WriteLine("!!!An error occurred while adding history of deleted Doctor!!!");
            }
        }
        public static void addAppointmentToHistory(int id)
        {
            using StreamWriter sw = new StreamWriter("DeletedAppointments.txt", append: true);
            string connectionString = "Data Source=(localdb)\\ProjectModels;Initial Catalog=HospitalManagementSystem;Integrated Security=True;";
            using SqlConnection connection = new SqlConnection(connectionString);
            try
            {
                Appointment p = new Appointment();
                string find = "select * from Appointments where AppointmentId = @AppointmentId";
                using SqlCommand findCommand = new SqlCommand(find, connection);
                findCommand.Parameters.AddWithValue("@AppointmentId", id);
                connection.Open();
                using SqlDataReader reader = findCommand.ExecuteReader();
                while (reader.Read())
                {
                    p.AppointmentId = reader.GetInt32(0);
                    p.AppointmentDate = reader.GetDateTime(1);
                    p.PatientId = reader.GetInt32(2);
                    p.DoctorId = reader.GetInt32(3);
                }
                DeletedAppointmentRecord record = new();
                record.Appointment = p;
                record.DeletionTimestamp = DateTime.Now;
                string jsonRecord = JsonSerializer.Serialize(record);
                sw.WriteLine(jsonRecord);
            }
            catch (Exception ex)
            {
                Console.WriteLine("!!!An error occurred while adding history of deleted Appointment!!!");
            }
        }
        public void viewAppointmentsHistory()
        {
            using StreamReader sr = new StreamReader("DeletedAppointments.txt");
            string line;
            while ((line = sr.ReadLine()) != null)
            {
                DeletedAppointmentRecord record = JsonSerializer.Deserialize<DeletedAppointmentRecord>(line);
                Console.WriteLine($"Appointment ID: {record.Appointment.AppointmentId}  Date: {record.Appointment.AppointmentDate}  Patient ID: {record.Appointment.PatientId}  Doctor ID: {record.Appointment.DoctorId}  Deletion Timestamp: {record.DeletionTimestamp}");
            }
        }
        public void viewPatientsHistory()
        {
            using StreamReader sr = new StreamReader("DeletedPatients.txt");
            string line;
            while ((line = sr.ReadLine()) != null)
            {
                DeletedPatientRecord record = JsonSerializer.Deserialize<DeletedPatientRecord>(line);
                Console.WriteLine($"Patient ID: {record.Patient.PatientId}  Name: {record.Patient.Name}  Email: {record.Patient.Email}  Deletion Timestamp: {record.DeletionTimestamp}");
            }
        }
        public void viewDoctorsHistory()
        {
            using StreamReader sr = new StreamReader("DeletedDoctors.txt");
            string line;
            while ((line = sr.ReadLine()) != null)
            {
                DeletedDoctorRecord record = JsonSerializer.Deserialize<DeletedDoctorRecord>(line);
                Console.WriteLine($"Doctor ID: {record.Doctor.DoctorId}  Name: {record.Doctor.Name}  Specialization: {record.Doctor.Specialization}  Deletion Timestamp: {record.DeletionTimestamp}");
            }
        }
    }
}
