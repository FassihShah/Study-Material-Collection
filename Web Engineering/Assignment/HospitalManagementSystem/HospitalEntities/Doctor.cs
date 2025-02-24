
namespace HospitalEntities
{
    public class Doctor
    {
        int doctorId;
        string name;
        string specialization;
        public Doctor()
        {
        }
        public int DoctorId
        {
            get { return doctorId; }
            set { doctorId = value; }
        }
        public string Name
        {
            get { return name; }
            set { name = value; }
        }
        public string Specialization
        {
            get { return specialization; }
            set { specialization = value; }
        }
    }
}
