using Problem.equipments;
using Problem.medics;
using Problem.servises;

namespace Problem
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Medic medic = Director.GetPediatr("Владимир", new Pila());

            medic.GetInfo();
            medic.UseYourEquipment();
            medic.Diagnose();

            Medic medic1 = Director.GetHirurg("Петр", new Ucol());

            medic1.GetInfo();
            medic1.UseYourEquipment();
            medic1.Diagnose();
        }
    }
}
