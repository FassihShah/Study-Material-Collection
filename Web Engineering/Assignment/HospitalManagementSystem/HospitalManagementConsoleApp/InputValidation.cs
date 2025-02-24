
using HospitalEntities;
using HospitalManagementDAL;
using Microsoft.Data.SqlClient;

namespace HospitalManagementConsoleApp
{
    public class InputValidation
    {
        AppointmentDataAccess appointmentData = new AppointmentDataAccess();
        public bool isValidEmail(string email)
        {
            return email.Contains('@');
        }
        public bool isValidName(string name)
        {
            return !string.IsNullOrWhiteSpace(name) && name.Length <= 50;
        }
        public bool isValidDisease(string disease)
        {
            return !string.IsNullOrWhiteSpace(disease) && disease.Length <= 50;
        }
        public bool isValidSpecialization(string specialization)
        {
            return !string.IsNullOrWhiteSpace(specialization) && specialization.Length <= 50;
        }
        public bool isValidAppointmentDate(int doctorId, DateTime date)
        {
            if(date <= DateTime.Now)
                return false;
            return !appointmentData.isAppointmentConflicting(date, doctorId); 
        }
    }
}
