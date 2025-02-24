using HospitalEntities;
using Microsoft.Data.SqlClient;

namespace HospitalManagementDAL
{
    public class PatientDataAccess
    {
        string connectionString = "Data Source=(localdb)\\ProjectModels;Initial Catalog=HospitalManagementSystem;Integrated Security=True;";
        AppointmentDataAccess appointments = new AppointmentDataAccess();
        public void insertPatient(Patient p)
        {
            string query = "insert into Patients(Name, Email, Disease) values(@Name, @Email, @Disease)";
            SqlConnection connection = new SqlConnection(connectionString);
            try
            {
                SqlCommand command = new SqlCommand(query, connection);
                command.Parameters.AddWithValue("@Name", p.Name);
                command.Parameters.AddWithValue("@Email", p.Email);
                command.Parameters.AddWithValue("@Disease", p.Disease);

                connection.Open();
                command.ExecuteNonQuery();
            }
            catch (Exception ex)
            {
                Console.WriteLine("!!!An error occurred while inserting the new Patient!!!");
            }
            finally
            {
                connection.Close();
            }
        }
        public List<Patient> getAllPatientsFromDatabase()
        {
            string query = "select * from Patients";
            SqlConnection connection = new SqlConnection(connectionString);
            List<Patient> patients = new List<Patient>();
            try
            {
                SqlCommand command = new SqlCommand(query, connection);
                connection.Open();
                SqlDataReader reader = command.ExecuteReader();
                while (reader.Read())
                {
                    Patient p = new Patient();
                    p.PatientId = reader.GetInt32(0);
                    p.Name = reader.GetString(1);
                    p.Email = reader.GetString(2);
                    p.Disease = reader.GetString(3);
                    patients.Add(p);
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine("!!!An error occurred while reading Patients from the database!!!");
            }
            finally
            {
                connection.Close();
            }
            return patients;
        }

        public void updatePatientInDatabase(Patient p)
        {
            string query = "update Patients set Name = @Name, Email = @Email, Disease = @Disease where PatientId = @PatientId";
            SqlConnection connection = new SqlConnection(connectionString);
            try
            {
                SqlCommand command = new SqlCommand(query, connection);
                command.Parameters.AddWithValue("@Name", p.Name);
                command.Parameters.AddWithValue("@Email", p.Email);
                command.Parameters.AddWithValue("@Disease", p.Disease);
                command.Parameters.AddWithValue("@PatientId", p.PatientId);

                connection.Open();
                command.ExecuteNonQuery();
            }
            catch (Exception ex)
            {
                Console.WriteLine("!!!An error occurred while updating Patient data!!!");
            }
            finally
            {
                connection.Close();
            }
        }

        public void deletePatientFromDatabase(int patientId)
        {
            string query = "delete from Patients where PatientId = @PatientId";
            SqlConnection connection = new SqlConnection(connectionString);
            try
            {
                deleteRespectiveAppointments(patientId);
                HistoryLogger.addPatientToHistory(patientId);

                SqlCommand command = new SqlCommand(query, connection);
                command.Parameters.AddWithValue("@PatientId", patientId);

                connection.Open();
                command.ExecuteNonQuery();
            }
            catch (Exception ex)
            {
                Console.WriteLine("!!!An error occurred while deleting Patient!!!");
            }
            finally
            {
                connection.Close();
            }
        }

        private void deleteRespectiveAppointments(int id)
        {
            string query = "select AppointmentId from Appointments where PatientId = @PatientId";
            SqlConnection connection = new SqlConnection(connectionString);
            try
            {
                SqlCommand command = new SqlCommand(query, connection);
                command.Parameters.AddWithValue("@PatientId", id);

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
                Console.WriteLine("!!!An error occurred while deleting respective appointments of the patient!!!");
            }
            finally
            {
                connection.Close();
            }
        }

        public List<Patient> searchPatientsInDatabase(string name)
        {
            string query = "select * from Patients where Name = @Name";
            SqlConnection connection = new SqlConnection(connectionString);
            List<Patient> patients = new List<Patient>();
            try
            {
                SqlCommand command = new SqlCommand(query, connection);
                command.Parameters.AddWithValue("@Name", name);

                connection.Open();
                SqlDataReader reader = command.ExecuteReader();
                while (reader.Read())
                {
                    Patient p = new Patient();
                    p.PatientId = reader.GetInt32(0);
                    p.Name = reader.GetString(1);
                    p.Email = reader.GetString(2);
                    p.Disease = reader.GetString(3);
                    patients.Add(p);
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine("!!!An error occurred while searching Patients from the database!!!");
            }
            finally
            {
                connection.Close();
            }
            return patients;
        }

        public bool isPatientInDatabase(int id)
        {
            string query = "select COUNT(*) from Patients where PatientId = @PatientId";
            SqlConnection connection = new SqlConnection(connectionString);
            int count = 0;
            try
            {
                SqlCommand command = new SqlCommand(query, connection);
                command.Parameters.AddWithValue("@PatientId", id);

                connection.Open();
                count = (int)command.ExecuteScalar();
            }
            catch (Exception ex)
            {
                Console.WriteLine("!!!An error occurred while checking if patient is in the database!!!");
            }
            finally
            {
                connection.Close();
            }
            return count > 0;
        }

        public Patient getPatient(int id)
        {
            if (!isPatientInDatabase(id))
                return null;

            string query = "select * from Patients where PatientId = @PatientId";
            SqlConnection connection = new SqlConnection(connectionString);
            Patient p = new Patient();
            try
            {
                SqlCommand command = new SqlCommand(query, connection);
                command.Parameters.AddWithValue("@PatientId", id);

                connection.Open();
                SqlDataReader reader = command.ExecuteReader();
                if (reader.Read())
                {
                    p.PatientId = reader.GetInt32(0);
                    p.Name = reader.GetString(1);
                    p.Email = reader.GetString(2);
                    p.Disease = reader.GetString(3);
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine("!!!An error occurred while getting patient from the database!!!");
            }
            finally
            {
                connection.Close();
            }
            return p;
        }
    }
}
