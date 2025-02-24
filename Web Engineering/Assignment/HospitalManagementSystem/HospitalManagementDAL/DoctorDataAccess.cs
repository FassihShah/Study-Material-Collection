using HospitalEntities;
using Microsoft.Data.SqlClient;

namespace HospitalManagementDAL
{
    public class DoctorDataAccess
    {
        string connectionString = "Data Source=(localdb)\\ProjectModels;Initial Catalog=HospitalManagementSystem;Integrated Security=True;";
        AppointmentDataAccess appointments = new AppointmentDataAccess();

        public void insertDoctor(Doctor d)
        {
            string query = "insert into Doctors(Name, Specialization) values(@Name, @Specialization)";
            SqlConnection connection = new SqlConnection(connectionString);
            try
            {
                SqlCommand command = new SqlCommand(query, connection);
                command.Parameters.AddWithValue("@Name", d.Name);
                command.Parameters.AddWithValue("@Specialization", d.Specialization);

                connection.Open();
                command.ExecuteNonQuery();
            }
            catch (Exception ex)
            {
                Console.WriteLine("!!!An error occurred while inserting new Doctor!!!");
            }
            finally
            {
                connection.Close();
            }
        }

        public List<Doctor> getAllDoctorsFromDatabase()
        {
            string query = "select * from Doctors";
            SqlConnection connection = new SqlConnection(connectionString);
            List<Doctor> doctors = new List<Doctor>();
            try
            {
                SqlCommand command = new SqlCommand(query, connection);
                connection.Open();
                SqlDataReader reader = command.ExecuteReader();
                while (reader.Read())
                {
                    Doctor d = new Doctor();
                    d.DoctorId = reader.GetInt32(0);
                    d.Name = reader.GetString(1);
                    d.Specialization = reader.GetString(2);
                    doctors.Add(d);
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine("!!!An error occurred while reading Doctors from database!!!");
            }
            finally
            {
                connection.Close();
            }
            return doctors;
        }

        public void updateDoctorInDatabase(Doctor d)
        {
            string query = "update Doctors set Name = @Name, Specialization = @Specialization where DoctorId = @DoctorId";
            SqlConnection connection = new SqlConnection(connectionString);
            try
            {
                SqlCommand command = new SqlCommand(query, connection);
                command.Parameters.AddWithValue("@Name", d.Name);
                command.Parameters.AddWithValue("@Specialization", d.Specialization);
                command.Parameters.AddWithValue("@DoctorId", d.DoctorId);

                connection.Open();
                command.ExecuteNonQuery();
            }
            catch (Exception ex)
            {
                Console.WriteLine("!!!An error occurred while updating Doctor data!!!");
            }
            finally
            {
                connection.Close();
            }
        }

        public void deleteDoctorFromDatabase(int doctorId)
        {
            string query = "delete from Doctors where DoctorId = @DoctorId";
            SqlConnection connection = new SqlConnection(connectionString);
            try
            {
                deleteRespectiveAppointments(doctorId);
                HistoryLogger.addDoctorToHistory(doctorId);

                SqlCommand command = new SqlCommand(query, connection);
                command.Parameters.AddWithValue("@DoctorId", doctorId);

                connection.Open();
                command.ExecuteNonQuery();
            }
            catch (Exception ex)
            {
                Console.WriteLine("!!!An error occurred while deleting Doctor!!!");
            }
            finally
            {
                connection.Close();
            }
        }

        private void deleteRespectiveAppointments(int id)
        {
            string query = "select AppointmentId from Appointments where DoctorId = @DoctorId";
            SqlConnection connection = new SqlConnection(connectionString);
            try
            {
                SqlCommand command = new SqlCommand(query, connection);
                command.Parameters.AddWithValue("@DoctorId", id);

                connection.Open();
                SqlDataReader reader = command.ExecuteReader();
                while (reader.Read())
                {
                    int appointmentId = reader.GetInt32(0);
                    appointments.deleteAppointmentFromDatabase(appointmentId);
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine("!!!An error occurred while deleting respective appointments of doctor!!!");
            }
            finally
            {
                connection.Close();
            }
        }

        public List<Doctor> searchDoctorsInDatabase(string specialization)
        {
            string query = "select * from Doctors where Specialization = @Specialization";
            SqlConnection connection = new SqlConnection(connectionString);
            List<Doctor> doctors = new List<Doctor>();
            try
            {
                SqlCommand command = new SqlCommand(query, connection);
                command.Parameters.AddWithValue("@Specialization", specialization);

                connection.Open();
                SqlDataReader reader = command.ExecuteReader();
                while (reader.Read())
                {
                    Doctor d = new Doctor();
                    d.DoctorId = reader.GetInt32(0);
                    d.Name = reader.GetString(1);
                    d.Specialization = reader.GetString(2);
                    doctors.Add(d);
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine("!!!An error occurred while searching Doctors from database!!!");
            }
            finally
            {
                connection.Close();
            }
            return doctors;
        }

        public bool isDoctorInDatabase(int id)
        {
            string query = "select COUNT(*) from Doctors where DoctorId = @DoctorId";
            SqlConnection connection = new SqlConnection(connectionString);
            int count = 0;
            try
            {
                SqlCommand command = new SqlCommand(query, connection);
                command.Parameters.AddWithValue("@DoctorId", id);

                connection.Open();
                count = (int)command.ExecuteScalar();
            }
            catch (Exception ex)
            {
                Console.WriteLine("!!!An error occurred while checking if doctor is in database!!!");
            }
            finally
            {
                connection.Close();
            }
            return count > 0;
        }

        public Doctor getDoctor(int id)
        {
            if (!isDoctorInDatabase(id))
                return null;
            string query = "select * from Doctors where DoctorId = @DoctorId";
            SqlConnection connection = new SqlConnection(connectionString);
            Doctor d = new Doctor();
            try
            {
                SqlCommand command = new SqlCommand(query, connection);
                command.Parameters.AddWithValue("@DoctorId", id);

                connection.Open();
                SqlDataReader reader = command.ExecuteReader();
                if (reader.Read())
                {
                    d.DoctorId = reader.GetInt32(0);
                    d.Name = reader.GetString(1);
                    d.Specialization = reader.GetString(2);
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine("!!!An error occurred while getting doctor from the database!!!");
            }
            finally
            {
                connection.Close();
            }
            return d;
        }
    }
}
