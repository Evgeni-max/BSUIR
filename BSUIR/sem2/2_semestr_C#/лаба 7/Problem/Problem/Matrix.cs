using System;
using System.Collections.Generic;
using System.Diagnostics.Metrics;
using System.Linq;
using System.Runtime.ExceptionServices;
using System.Text;
using System.Threading.Tasks;
using static System.Net.Mime.MediaTypeNames;
using static System.Runtime.InteropServices.JavaScript.JSType;

namespace Problem
{
    internal class Matrix
    {
        public int[,] matrix { get; set; }

        public int opredelitel { get; private set; }
        private void FindOpredelitel()
        {
            opredelitel = matrix[0, 0] * matrix[1, 1] - matrix[0, 1] * matrix[1, 0];
        }

        public Matrix(int[,] matrix) { this.matrix = matrix; FindOpredelitel(); }
        public Matrix(int first, int second, int third, int fouth) {
            if (first is int && second is int && third is int && fouth is int)
            {
                matrix = new int[2, 2] { { first, second }, { third, fouth } };
            }
            else throw new Exception("неправильный ввод");
        }

        public static Matrix operator +(Matrix mat, Matrix number) {
            return new Matrix(mat.matrix[0, 0] + number.matrix[0, 0], mat.matrix[0, 1] + number.matrix[0, 1], mat.matrix[1, 0] + number.matrix[1, 0], mat.matrix[1, 1] + number.matrix[1, 1]);
        }

        public static Matrix operator -(Matrix mat, Matrix number)
        {
            return new Matrix(mat.matrix[0, 0] - number.matrix[0, 0], mat.matrix[0, 1] - number.matrix[0, 1], mat.matrix[1, 0] - number.matrix[1, 0], mat.matrix[1, 1] - number.matrix[1, 1]);
        }

        public static Matrix operator *(Matrix mat, Matrix number)
        {
            return new Matrix(mat.matrix[0, 0] * number.matrix[0, 0], mat.matrix[0, 1] * number.matrix[0, 1], mat.matrix[1, 0] * number.matrix[1, 0], mat.matrix[1, 1] * number.matrix[1, 1]);
        }

        public static Matrix operator /(Matrix mat, Matrix number)
        {
            return new Matrix(mat.matrix[0, 0] / number.matrix[0, 0], mat.matrix[0, 1] / number.matrix[0, 1], mat.matrix[1, 0] / number.matrix[1, 0], mat.matrix[1, 1] / number.matrix[1, 1]);
        }
        public static Matrix operator ++(Matrix mat)
        {
            return new Matrix(mat.matrix[0, 0] + 1, mat.matrix[0, 1] + 1, mat.matrix[1, 0] + 1, mat.matrix[1, 1] + 1);
        }
        public static Matrix operator --(Matrix mat)
        {
            return new Matrix(mat.matrix[0, 0] - 1, mat.matrix[0, 1] - 1, mat.matrix[1, 0] - 1, mat.matrix[1, 1] - 1);
        }
        public int this[int n1, int n2] {
            get { 
                return matrix[n1, n2]; 
            }
            set {
                if (n1 < 0 || n2 < 0 || n1 > 1 || n2 > 1)
                {
                    throw new Exception("индекс вне диапазона");
                }
                matrix[n1, n2] = value; 
            }
        }

        public static explicit operator int(Matrix param)
        {
            return param.opredelitel;
        }

        public static explicit operator Matrix(int param)
        {
            return new Matrix(param, 0, 0, 1);
        }

        public static bool operator true(Matrix counter1)
        {
            return counter1.opredelitel != 0;
        }
        public static bool operator false(Matrix counter1)
        {
            return counter1.opredelitel == 0;
        }

        public static bool operator ==(Matrix mat, Matrix number)
        {
            if (mat.matrix[0, 0] == number.matrix[0, 0] 
                && mat.matrix[0, 1] == number.matrix[0, 1] 
                && mat.matrix[1, 0] == number.matrix[1, 0] 
                && mat.matrix[1, 1] == number.matrix[1, 1]) { return true; }
            else return false;
        }

        public static bool operator !=(Matrix mat, Matrix number)
        {
            if (!(mat == number)) { return true; }
            else return false;
        }

        public string ToString()
        {
            return matrix[0, 0].ToString() + ' ' 
                + matrix[0, 1].ToString() + ' '
                + matrix[1, 0].ToString() + ' '
                + matrix[1, 1].ToString();
        }
    }
}
