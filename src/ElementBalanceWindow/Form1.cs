using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ElementBalanceWindow
{
    public partial class Form1 : Form
    {
        string eq;
        public Form1()
        {
            InitializeComponent();
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            input.Clear();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            eq = input.Text.Trim();
            IntPtr equation = Marshal.StringToHGlobalAnsi(eq);
            IntPtr result = ElementBalanceWindow.Program.ElementBalance(equation);
            output.Text = Marshal.PtrToStringAnsi(result);
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void Kp(object sender, KeyPressEventArgs e)
        {
            char judge = e.KeyChar;
            if(judge == '\r')
            {
                eq = input.Text.Trim();
                IntPtr equation = Marshal.StringToHGlobalAnsi(eq);
                IntPtr result = ElementBalanceWindow.Program.ElementBalance(equation);
                output.Text = Marshal.PtrToStringAnsi(result);
                
            }
            
        }

        private void output_TextChanged(object sender, EventArgs e)
        {

        }
    }
}
