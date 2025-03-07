﻿using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using _353503_Martynkech_Lab3.Collections;

namespace _353503_Martynkech_Lab3.Entities
{
    internal class Journal : IEnumerable
    {
        private List<string> events;
        public Journal()
        {
            events = new List<string>();
        }

        public Journal(Journal journal)
        {
            events = journal.events;
        }

        public IEnumerator GetEnumerator()
        {
            IEnumerator enumerator = new JournalEnumerator(events);
            for (int i = 0; i < events.Count; i++)
            {
                yield return enumerator.Current;
                enumerator.MoveNext();
            }
        }

        public void GetEvent(string name)
        {
            events.Add(name);
        }
    }

    internal class JournalEnumerator : IEnumerator
    {
        string[] events;
        int position;

        public JournalEnumerator(List<string> list)
        {
            events = new string[list.Count];
            for (int i = 0; i < list.Count; i++)
            {
                events[i] = list[i];
            }
            position = 0;
        }
        public object Current
        {
            get { return events[position]; }
        }

        public bool MoveNext()
        {
            if (position < events.Length)
            {
                ++position;
                return true;
            }
            else { return false; }
        }

        public void Reset()
        {
            position = 0;
        }
    }
}
