using HospitalEntities;
using Microsoft.Data.SqlClient;

namespace HospitalManagementDAL
{
    public class AppointmentDataAccess
    {
        string connectionString = "Data Source=(localdb)\\ProjectModels;Initial Catalog=HospitalManagementSystem;Integrated Security=True;";
        public void insertAppointment(Appointment a)
        {
            string query = "insert into Appointments(AppointmentDate, PatientId, DoctorId) values(@AppointmentDate, @PatientId, @DoctorId)";
            SqlConnection connection = new SqlConnection(connectionString);
            try
            {
                SqlCommand command = new SqlCommand(query, connection);
                command.Parameters.AddWithValue("@AppointmentDate", a.AppointmentDate);
                command.Parameters.AddWithValue("@PatientId", a.PatientId);
                command.Parameters.AddWithValue("@DoctorId", a.DoctorId);

                connection.Open();
                command.ExecuteNonQuery();
            }
            catch (Exception ex)
            {
                Console.WriteLine("!!!An error occurred while inserting new Appointment!!!");
            }
            finally
            {
                connection.Close();
            }
        }
        public List<Appointment> getAllAppointmentsFromDatabase()
        {
            string query = "select * from Appointments";
            SqlConnection connection = new SqlConnection(connectionString);
            List<Appointment> appointments = new List<Appointment>();
            try
            {
                SqlCommand command = new SqlCommand(query, connection);
                connection.Open();
                SqlDataReader reader = command.ExecuteReader();
                while (reader.Read())
                {
                    Appointment p = new Appointment();
                    p.AppointmentId = reader.GetInt32(0);
                    p.AppointmentDate = reader.GetDateTime(1);
                    p.PatientId = reader.GetInt32(2);
                    p.DoctorId = reader.GetInt32(3);
                    appointments.Add(p);
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine("!!!An error occurred while reading Appointments from database!!!");
            }
            finally
            {
                connection.Close();
            }
            return appointments;
        }
        public void updateAppointmentInDatabase(Appointment a)
        {
            string query = "update Appointments set AppointmentDate = @AppointmentDate, PatientId = @PatientId, DoctorId = @DoctorId where AppointmentId = @AppointmentId";
            SqlConnection connection = new SqlConnection(connectionString);
            try
            {
                SqlCommand command = new SqlCommand(query, connection);
                command.Parameters.AddWithValue("@AppointmentDate", a.AppointmentDate);
                command.Parameters.AddWithValue("@PatientId", a.PatientId);
                command.Parameters.AddWithValue("@DoctorId", a.DoctorId);
                command.Parameters.AddWithValue("@AppointmentId", a.AppointmentId);
                connection.Open();
                command.ExecuteNonQuery();
            }
            catch (Exception ex)
            {
                Console.WriteLine("!!!An error occurred while updating Appointment data!!!");
            }
            finally
            {
                connection.Close();
            }
        }
        public void deleteAppointmentFromDatabase(int appointmentId)
        {
            string query = "delete from Appointments where AppointmentId = @AppointmentId";
            SqlConnection connection = new SqlConnection(connectionString);
            try
            {
                HistoryLogger.addAppointmentToHistory(appointmentId);

                SqlCommand command = new SqlCommand(query, connection);
                command.Parameters.AddWithValue("@AppointmentId", appointmentId);

                connection.Open();
                command.ExecuteNonQuery();
            }
            catch (Exception ex)
            {
                Console.WriteLine("!!!An error occurred while deleting Appointment!!!");
            }
            finally
            {
                connection.Close();
            }
        }
        public List<Appointment> searchAppointmentInDatabase(int doctorId, int patientId)
        {
            string query = "select * from Appointments where DoctorId = @DoctorId and PatientId = @PatientId";
            SqlConnection connection = new SqlConnection(connectionString);
            List<Appointment> appointments = new List<Appointment>();
            try
            {
                SqlCommand command = new SqlCommand(query, connection);
                command.Parameters.AddWithValue("@DoctorId", doctorId);
                command.Parameters.AddWithValue("@PatientId", patientId);

                connection.Open();
                SqlDataReader reader = command.ExecuteReader();
                while (reader.Read())
                {
                    Appointment p = new Appointment();
                    p.AppointmentId = reader.GetInt32(0);
                    p.AppointmentDate = reader.GetDateTime(1);
                    p.PatientId = reader.GetInt32(2);
                    p.DoctorId = reader.GetInt32(3);
                    appointments.Add(p);
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine("!!!An error occurred while searching Appointments from database!!!");
            }
            finally
            {
                connection.Close();
            }
            return appointments;
        }
        public bool isAppointmentConflicting(DateTime date, int doctorId)
        {
            string query = "select COUNT(*) from Appointments where DoctorId = @DoctorId and AppointmentDate = @AppointmentDate";
            SqlConnection connection = new SqlConnection(connectionString);
            int count = 0;
            try
            {
                SqlCommand command = new SqlCommand(query, connection);
                command.Parameters.AddWithValue("@DoctorId", doctorId);
                command.Parameters.AddWithValue("@AppointmentDate", date);

                connection.Open();
                count = (int)command.ExecuteScalar();
            }
            catch (Exception ex)
            {
                Console.WriteLine("!!!An error occurred while checking conflicting appointments from database!!!");
            }
            finally
            {
                connection.Close();
            }
            return count > 0;
        }
        public bool isAppointmentInDatabase(int id)
        {
            string query = "select COUNT(*) from Appointments where AppointmentId = @AppointmentId";
            SqlConnection connection = new SqlConnection(connectionString);
            int count = 0;
            try
            {
                SqlCommand command = new SqlCommand(query, connection);
                command.Parameters.AddWithValue("@AppointmentId", id);

                connection.Open();
                count = (int)command.ExecuteScalar();
            }
            catch (Exception ex)
            {
                Console.WriteLine("!!!An error occurred while checking if appointment is in the database!!!");
            }
            finally
            {
                connection.Close();
            }
            return count > 0;
        }
        public Appointment getAppointment(int id)
        {
            if (!isAppointmentInDatabase(id))
                return null;
            string query = "select * from Appointments where AppointmentId = @AppointmentId";
            SqlConnection connection = new SqlConnection(connectionString);
            Appointment appointment = new Appointment();
            try
            {
                SqlCommand command = new SqlCommand(query, connection);
                command.Parameters.AddWithValue("@AppointmentId", id);
                connection.Open();
                SqlDataReader reader = command.ExecuteReader();
                if (reader.Read())
                {
                    appointment.AppointmentId = reader.GetInt32(0);
                    appointment.PatientId = reader.GetInt32(1);
                    appointment.DoctorId = reader.GetInt32(2);
                    appointment.AppointmentDate = reader.GetDateTime(3);
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine("!!!An error occurred while getting appointment from the database!!!");
            }
            finally
            {
                connection.Close();
            }
            return appointment;
        }
    }
}
