using Lab_1_Task_1_353502_BURCHUCK_Lab_1_.Collections;
using Lab_1_Task_1_353502_BURCHUCK_Lab_1_.Interfaces;
using System;
using System.Collections;
using System.Collections.Generic;
using System.Reflection.Metadata.Ecma335;
using System.Security.Cryptography.X509Certificates;

namespace Lab_1_Task_1_353502_BURCHUCK_Lab_1_.Collections
{
    sealed internal class Node<T>
    {
        Node<T> next = null;
        Node<T> prev = null;
        T value;

        public Node(Node<T> next, Node<T> prev, T value)
        {
            this.next = next;
            this.prev = prev;
            this.value = value;
        }

        public Node(T value)
        {
            this.value = value;
        }

        public Node<T> Next { get { return next; } set { next = value; } }
        public Node<T> Prev { get { return prev; } set { prev = value; } }
        public T Value { get { return value; } set { this.value = value; } }
        public void Add(T value)
        {
            this.next = new Node<T>(null, this, value);
        }

        public bool DoesNextExist() { return next != null; }
    }

    internal class MyCustomCollection<T> : Interfaces.ICustomCollection<T> , IEnumerable<T>
    {
        Node<T>? first;
        Node<T>? last;
        int count;
        Node<T>? cursor;

        public MyCustomCollection()
        {
            first = null;
            last = null;
            count = 0;
            cursor = first;
        }

        public T this[int index]
        {
            get
            {
                Node<T>? node = first;
                int i = 0;
                while (i < count)
                {
                    if (i == index)
                    {
                        if (node != null)
                        {
                            return node.Value;
                        }
                        else
                        {
                            throw new Exception("Node is null.");
                        }
                    }
                    ++i;
                    if (node != null)
                    {
                        node = node.Next;
                    }
                }
                throw new IndexOutOfRangeException("Index out of bounds.");
            }
            set
            {
                Node<T>? node = first;
                int i = 0;
                while (i < count)
                {
                    if (i == index)
                    {
                        if (node != null)
                        {
                            node.Value = value;
                            return;
                        }
                        else
                        {
                            throw new Exception("Node is null.");
                        }
                    }
                    ++i;
                    if (node != null)
                    {
                        node = node.Next;
                    }
                }
                throw new Exception("Index out of bounds.");
            }
        }

        public int Count { get { return count; } }

        public void Add(T item)
        {
            if (last != null)
            {
                last.Add(item);
                last = last.Next;
            }
            else
            {
                first = last = new Node<T>(item);
            }

            ++count;

        }

        public T Current()
        {
            if (cursor == null)
            {
                throw new Exception("Cursor is null.");
            }
            return cursor.Value;
        }

        public void Next()
        {
            if (cursor == null || !cursor.DoesNextExist())
            {
                throw new Exception("Next node does not exist.");
            }
            cursor = cursor.Next;
        }

        public void Remove(T item)
        {
            if (count != 0)
            {
                Node<T>? temp1 = FindItem(item, first);
                if (temp1 != null)
                {
                    if (temp1 == first)
                    {
                        first = temp1.Next;
                        if (first != null)
                        {
                            first.Prev = null;
                        }
                    }
                    else if (temp1 == last)
                    {
                        last = temp1.Prev;
                        if (last != null)
                        {
                            last.Next = null;
                        }
                    }
                    else
                    {
                        Node<T> temp2 = temp1.Next;
                        temp2.Prev = temp1.Prev;
                        temp1.Prev.Next = temp2;
                    }
                    --count;
                }
                else
                {
                    throw new Exception("Item does not exist.");
                }
            }
            else
            {
                throw new Exception("Item does not exist.");
            }
        }

        private Node<T>? FindItem(T item, Node<T> node)
        {
            while (node != null)
            {
                if (node.Value.Equals(item)) return node;
                node = node.Next;
            }
            return null;
        }

        public T RemoveCurrent()
        {
            if (cursor == null)
            {
                throw new Exception("Cursor is null.");
            }

            Node<T> temp = cursor;

            if (cursor == first)
            {
                first = cursor.Next;
                if (first != null)
                {
                    first.Prev = null;
                }
            }
            else if (cursor == last)
            {
                last = cursor.Prev;
                if (last != null)
                {
                    last.Next = null;
                }
            }
            else
            {
                cursor.Prev.Next = cursor.Next;
                cursor.Next.Prev = cursor.Prev;
            }

            cursor = cursor.Next;
            T tempValue = temp.Value;
            --count;
            return tempValue;
        }

        public void Reset()
        {
            cursor = first;
        }

        public IEnumerator<T> GetEnumerator()
        {
            IEnumerator<T> enumerator = new MyCustomCollectionEnumerator<T>(first);
            for (int i = 0; i < count; ++i)
            {
                yield return enumerator.Current;
                enumerator.MoveNext();
            }
        }
        IEnumerator IEnumerable.GetEnumerator()
        {
            IEnumerator<T> enumerator = new MyCustomCollectionEnumerator<T>(first);
            for (int i = 0; i < count; ++i)
            {
                yield return enumerator.Current;
                enumerator.MoveNext();
            }
        }
    }

    internal class MyCustomCollectionEnumerator<T> : IEnumerator<T>
    {
        Node<T>? first;
        Node<T>? current;

        public MyCustomCollectionEnumerator(Node<T>? first)
        {
            this.current = this.first = first;
        }

        public object Current { get { return current.Value; } }

        T IEnumerator<T>.Current { get { return current.Value; } }
        public void Dispose()
        {
            throw new NotImplementedException();
        }

        public bool MoveNext()
        {
            if (current.Next != null)
            {
                current = current.Next;
                return true;
            }
            else
            {
                return false;
            }
        }

        public void Reset() => current = first;
    }
}
