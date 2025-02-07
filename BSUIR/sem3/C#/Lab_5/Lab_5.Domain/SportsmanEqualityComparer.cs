using System;
using System.Collections.Generic;
using System.Diagnostics.CodeAnalysis;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading.Tasks.Dataflow;

namespace Lab_5.Domain
{
    public class SportsmanEqualityComparer : IEqualityComparer<Sportsman>
    {
        public bool Equals(Sportsman? x, Sportsman? y)
        {
            return x.Name == y.Name && 
                   x.Age == y.Age && 
                   x.SportTypeName == y.SportTypeName && 
                   x.SportTypePopularity == y.SportTypePopularity;
        }

        public int GetHashCode([DisallowNull] Sportsman obj)
        {
            return obj.Name.GetHashCode() * obj.Age * obj.SportTypeName.GetHashCode() * obj.SportTypePopularity;
        }
    }
}
