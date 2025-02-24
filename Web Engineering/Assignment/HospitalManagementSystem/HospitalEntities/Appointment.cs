
namespace HospitalEntities
{
    public class Appointment
    {
        int appointmentId;
        int patientId;
        int doctorId;
        DateTime appointmentDate;
        public Appointment()
        {
        }
        public int AppointmentId
        {
            get { return appointmentId; }
            set { appointmentId = value; }
        }
        public int PatientId
        {
            get { return patientId; }
            set { patientId = value; }
        }
        public int DoctorId
        {
            get { return doctorId; }
            set { doctorId = value; }
        }
        public DateTime AppointmentDate
        {
            get { return appointmentDate; }
            set { appointmentDate = value; }
        }
    }
}
