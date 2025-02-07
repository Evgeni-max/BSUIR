using Lab_1_Task_1_353502_BURCHUCK_Lab_1_.Entities;
using Lab_1_Task_1_353502_BURCHUCK_Lab_1_.Interfaces.Collections;
using System;
using System.Numerics;

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

    internal class MyCustomCollection<T> : ICustomCollection<T> , IAdditionOperators<MyCustomCollection<T>, MyCustomCollection<T>, MyCustomCollection<T>> where T : INumber<T>
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
                        node = node.Next; // Перемещаемся к следующему узлу
                    }
                }
                throw new Exception("Index out of bounds.");
            }
            set
            {
                Node<T>? node = first; // node должен быть null допустимым значением
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
                        node = node.Next; // Перемещаемся к следующему узлу
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

        public T Sum<T>(T first, T second) where T : INumber<T>
        {
            return first + second;
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
                            last.Next = null!;
                        }
                    }
                    else
                    {
                        Node<T> temp2 = temp1.Next;
                        if (temp2 != null)
                        {
                            temp2.Prev = temp1.Prev;
                        }
                        if (temp1.Prev != null)
                        {
                            temp1.Prev.Next = temp2!;
                        }
                    }
                    --count;
                }
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

        public static MyCustomCollection<T> operator +(MyCustomCollection<T> left, MyCustomCollection<T> right)
        {
            MyCustomCollection<T> tmp = new MyCustomCollection<T>();
            for (int i = 0; i < left.Count; ++i)
            {
                tmp.Add(left[i]);
            }
            for (int i = 0; i < right.Count; ++i)
            {
                tmp.Add(right[i]);
            }
            return tmp;
        }
    }
}
