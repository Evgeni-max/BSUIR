using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PatientsLib.Entities
{
    public enum Diagnoses
    {
        None,
        Schizophrenia,
        Alzheimer,
        ProstaticIssues,
        LungCancer,
        ProstaticCancer,
        Infarct,
        HeartAtak,
        Diarrhea
    }
    public class BasicPatient
    {
        public string Name { get; set; }
        public int Age { get; set; }
        public Diagnoses Diagnose { get; set; }

        public BasicPatient(string name, int age, Diagnoses diagnoses)
        {
            Name = name;
            Age = age;
            Diagnose = diagnoses;
        }

        public BasicPatient()
        {
            Name = "";
            Age = 0;
            Diagnose = Diagnoses.None;
        }
    }
}
