using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;

namespace Compiladores_UI
{
    public partial class MainWindow : Form
    {

        private string CurrentFile;
        Compiladores_Project.Manager Compilador;

        public MainWindow()
        {
            InitializeComponent();
            CurrentFile = "";
            Compilador = new Compiladores_Project.Manager();            
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void Input_Field_TextChanged(object sender, EventArgs e)
        {
            
        }

        private void NewMenu_Click(object sender, EventArgs e)
        {
            if (Input_Field.Text.Trim() != "")
            {
                DialogResult Answer = MessageBox.Show("¿Desea guardar los cambios?", "Atencion", MessageBoxButtons.YesNoCancel);
                if (Answer == DialogResult.Yes)
                {
                    SaveFileAs();
                    Input_Field.Clear();
                }
                else if(Answer == DialogResult.No)
                {
                    Input_Field.Clear();
                }
            }
        }

        private void SaveFileAs()
        {
            SaveFileDialog SaveWindow = new SaveFileDialog();
            SaveWindow.Filter = "Textfile|.txt";
            SaveWindow.Title = "Guardar archivo";
            SaveWindow.ShowDialog();

            if(CurrentFile != "")
            {
                CurrentFile = SaveWindow.FileName;
                SaveFile();
            }
        }

        private void SaveFile()
        {
            string Code = Input_Field.Text.Trim();
            StreamWriter OutWriter = new StreamWriter(CurrentFile, false);
            OutWriter.Write(Code);
            OutWriter.Flush();
            OutWriter.Close();
        }

        private void OpenMenu_Click(object sender, EventArgs e)
        {
            if(CurrentFile != "")
            {
                SaveFileAs();
            }
            else
            {
                NewMenu_Click(sender, e);
            }
            OpenFileDialog OpenWindow = new OpenFileDialog();
            OpenWindow.Filter = "Text file| *.txt";
            OpenWindow.Title = "Load code";
            OpenWindow.CheckFileExists = true;
            OpenWindow.ShowDialog();

            if(OpenWindow.FileName != "")
            {
                StreamReader InWriter = new StreamReader(OpenWindow.FileName);
                string Textbuffer = InWriter.ReadToEnd();
                InWriter.Close();
                Input_Field.Text = Textbuffer;
            }
        }

        private void SaveMenu_Click(object sender, EventArgs e)
        {
            if(CurrentFile == "")
            {
                SaveFileAs();
            }
            else
            {
                SaveFile();
            }
        }

        private void SaveAsMenu_Click(object sender, EventArgs e)
        {
            SaveFileAs();
        }

        private void CloseMenu_Click(object sender, EventArgs e)
        {

        }

        private void FileMenu_Click(object sender, EventArgs e)
        {

        }

        private void CompileMenu_Click(object sender, EventArgs e)
        {
            string[] Details = Compilador.Compile(Input_Field.Text);
            Output_Field.Lines = Details;
        }
    }
}