using HospitalEntities;
using HospitalManagementDAL;

namespace HospitalManagementConsoleApp
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Menu menu = new Menu();
            int selection;
            do
            {
                menu.displayMainMenu();
                selection = int.Parse(Console.ReadLine());
                menu.handleUserSelection(selection);
            } 
            while (selection < 5);
        }
    }
}
