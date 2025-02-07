using _353503_Martynkevich_Lab1.Interfaces;
using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _353503_Martynkevich_Lab1.Collections
{
    public class Pair<T, U>
    {
        public Pair()
        {
        }

        public Pair(T first, U second)
        {
            this.First = first;
            this.Second = second;
        }

        public T First { get; set; }
        public U Second { get; set; }
    };

    public class MyCustomCollection<T>
        : ICustomCollection<T>, IEnumerable<T>
    {
        private class Node
        {
            private T data;
            private Node? next;

            public Node(T data)
            {
                this.data = data;
            }
            public T Data
            {
                get { return data; }
                set { data = value; }
            }

            public Node? Next
            {
                get { return next; }
                set { next = value; }
            }
        }

        private Node? pointer;
        private Node? begin;
        private Node? end;

        private int count;

        public MyCustomCollection()
        {
            this.pointer = null;
            this.begin = null;
            this.end = null;
            this.count = 0;
        }
        private void RemoveByPointer(Node pointerToRemove)
        {
            if (pointerToRemove == begin)
            {
                begin = begin.Next;

                if (pointer == pointerToRemove)
                {
                    pointer = begin;
                }

                --count;
                return;
            }
            Node? searchPointer = begin;

            // searching for pointer to remove
            while (searchPointer.Next != null)
            {
                if (pointerToRemove.Equals(searchPointer.Next))
                {
                    searchPointer.Next = pointerToRemove.Next;
                    count--;

                    // setting pointer to previous position when pointer to remove equals pointer
                    if (pointer == pointerToRemove)
                    {
                        pointer = searchPointer;
                    }

                    // setting end to previous position when pointer to remove equals pointer
                    if (end == pointerToRemove)
                    {
                        end = searchPointer;
                    }
                    return;
                }

                searchPointer = searchPointer.Next;
            }
            throw new Exception("Такого обьекта нет");
        }
        public T this[int index]
        {
            get
            {
                if (index < 0 || index > count - 1)
                {
                    throw new IndexOutOfRangeException();
                }

                Node searchPointer = begin;

                while (index-- > 0)
                {
                    searchPointer = searchPointer.Next;
                }

                return searchPointer.Data;
            }

            set
            {
                if (index < 0 || index > count - 1)
                {
                    throw new IndexOutOfRangeException();
                }

                Node searchPointer = begin;

                while (index-- > 0)
                {
                    searchPointer = searchPointer.Next;
                }

                searchPointer.Data = value;
            }
        }

        public int Count => count;

        public void Add(T item)
        {
            count++;

            // empty collection check
            if (end == null)
            {
                end = new Node(item);
                begin = end;
                pointer = begin;
                return;
            }

            end.Next = new Node(item);
            end = end.Next;
        }

        public T Current()
        {
            if (pointer == null)
            {
                throw new IndexOutOfRangeException();
            }

            return pointer.Data;
        }

        public void Next()
        {
            if (pointer == null)
            {
                throw new IndexOutOfRangeException();
            }

            pointer = pointer.Next;
        }

        public void Remove(T item)
        {
            if (begin == null)
            {
                return;
            }

            Node? searchPointer = begin;

            // searching for pointer to remove
            while (searchPointer != null)
            {
                if (searchPointer.Data.Equals(item))
                {
                    RemoveByPointer(searchPointer);
                    return;
                }
                searchPointer = searchPointer.Next;
            }

        }

        public T RemoveCurrent()
        {
            if (pointer == null)
            {
                throw new IndexOutOfRangeException();
            }

            T data = pointer.Data;
            RemoveByPointer(pointer);
            return data;
        }

        public void Reset()
        {
            pointer = begin;
        }

        public IEnumerator<T> GetEnumerator()
        {
            Node current = begin;
            while (current != null)
            {
                yield return current.Data;
                current = current.Next;
            }
        }

        IEnumerator IEnumerable.GetEnumerator()
        {
            return GetEnumerator();
        }

    }
}
