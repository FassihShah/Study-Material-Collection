
namespace HospitalEntities
{
    public class Patient
    {
        int patientId;
        string name;
        string email;
        string disease;
        public Patient()
        {

        }
        public int PatientId
        {
            get { return patientId; }
            set { patientId = value; }
        }
        public string Name
        {
            get { return name; }
            set { name = value; }
        }
        public string Email
        {
            get { return email; }
            set { email = value; }
        } 
        public string Disease
        {
            get { return disease; }
            set { disease = value; }
        }
    }
}
