using System;
using System.IO;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Windows.Interop;
using System.Diagnostics;

namespace GUI
{
    public partial class GUI : Form
    {
        private CppCLI m_Engine;
        private uint m_value;
        private string m_binPath;

        public GUI()
        {
            InitializeComponent();
            m_binPath = Path.GetDirectoryName(Path.GetDirectoryName(System.IO.Directory.GetCurrentDirectory()));
            m_Engine = new CppCLI(m_binPath);
            m_value = 3;
            m_prefixSearch_comboBox.AutoCompleteCustomSource = new AutoCompleteStringCollection();
            m_longestPrefixSearch_textBox.AutoCompleteCustomSource = new AutoCompleteStringCollection();
        }

        private void m_insert_button_Click(object sender, EventArgs e)
        {
            string str = m_manipulate_textbox.Text;

            if (str.Length == 0)
                return;

            bool ret = m_Engine.PutWord(str, m_value++);

            if (ret)
            {
                m_numOfWords_StatusLabel.Text = m_Engine.Size().ToString();
                m_manipulate_textbox.Text = "";
            }
        }

        private void m_delete_button_Click(object sender, EventArgs e)
        {

            // If empty, skip
            if (m_Engine.IsEmpty())
                return;

            string str = m_manipulate_textbox.Text;

            if (str.Length == 0)
                return;

            bool ret = m_Engine.DeleteWord(str);

            if (ret)
            {
                m_numOfWords_StatusLabel.Text = m_Engine.Size().ToString();
                m_manipulate_textbox.Text = "";
            }
        }

        private void m_clear_button_Click(object sender, EventArgs e)
        {
            // If empty, skip
            if (m_Engine.IsEmpty())
                return;

            m_Engine.ClearTree();
            m_words_richTextBox.Clear();
            m_numOfWords_StatusLabel.Text = m_Engine.Size().ToString();
        }

        private void m_prefixSearch_comboBox_TextChanged(object sender, EventArgs e)
        {
            // If empty, skip
            if (m_Engine.IsEmpty())
                return;

            if (m_prefixSearch_comboBox.Text.Length == 0)
            {
                try
                {
                    m_prefixSearch_comboBox.DroppedDown = false;
                }
                catch (System.ArgumentOutOfRangeException ex)
                {
                }

                m_prefixSearch_comboBox.Items.Clear();
                return;
            }

            if (m_prefixSearch_comboBox.DroppedDown != true)
            {
                m_prefixSearch_comboBox.DroppedDown = true;
                Cursor.Current = Cursors.Default;
            }

            m_prefixSearch_comboBox.Items.Clear();

            m_prefixSearch_comboBox.SelectionStart = m_prefixSearch_comboBox.Text.Length;

            string[] words = m_Engine.WordsWithPrefix(m_prefixSearch_comboBox.Text);

            if (words != null)
            {
                m_prefixSearch_comboBox.Items.AddRange(words);
            }
        }

        private void m_longestPrefixSearch_textBox_KeyDown(object sender, KeyEventArgs e)
        {
            // Activate on Enter
            if (e.KeyCode != Keys.Enter)
                return;

            // If empty, skip
            if (m_Engine.IsEmpty())
                return;

            string word = m_Engine.LongestPrefixOf(m_longestPrefixSearch_textBox.Text);

            if (word.Length > 0)
            {
                m_longestPrefixSearch_textBox.Text = word;
                m_longestPrefixSearch_textBox.SelectionStart = m_longestPrefixSearch_textBox.Text.Length;
                m_longestPrefixSearch_textBox.BackColor = Color.LightGreen;
            }
            else
            {
                m_longestPrefixSearch_textBox.BackColor = Color.Red;
                m_longestPrefixSearch_textBox.SelectionStart = m_longestPrefixSearch_textBox.Text.Length;
            }

        }

        private void m_longestPrefixSearch_textBox_TextChanged(object sender, EventArgs e)
        {
            if (m_longestPrefixSearch_textBox.BackColor != Color.White)
                m_longestPrefixSearch_textBox.BackColor = Color.White;
        }

        private void m_manipulate_textbox_KeyDown(object sender, KeyEventArgs e)
        {
            // If empty, skip
            if (m_manipulate_textbox.Text.Length == 0)
                return;

            if (e.KeyCode == Keys.Enter)
                m_insert_button_Click(sender, e);
            else if (e.KeyCode == Keys.Delete)
                m_delete_button_Click(sender, e);
        }

        private void m_wordMatchSearch_comboBox_TextChanged(object sender, EventArgs e)
        {
            // If empty, skip
            if (m_Engine.IsEmpty())
                return;

            if (m_wordMatchSearch_comboBox.Text.Length == 0)
            {
                try
                {
                    m_wordMatchSearch_comboBox.DroppedDown = false;
                }
                catch (System.ArgumentOutOfRangeException ex)
                {
                }

                m_wordMatchSearch_comboBox.Items.Clear();
                return;
            }

            if (m_wordMatchSearch_comboBox.DroppedDown != true)
            {
                m_wordMatchSearch_comboBox.DroppedDown = true;
                Cursor.Current = Cursors.Default;
            }

            m_wordMatchSearch_comboBox.Items.Clear();

            m_wordMatchSearch_comboBox.SelectionStart = m_wordMatchSearch_comboBox.Text.Length;

            string[] data = m_Engine.WordsThatMatch(m_wordMatchSearch_comboBox.Text);

            if (data != null)
                m_wordMatchSearch_comboBox.Items.AddRange(data);
        }

        private void refreshToolStripMenuItem_Click(object sender, EventArgs e)
        {
            m_words_richTextBox.ResetText();

            if (m_Engine.IsEmpty())
                return;

            string[] words = m_Engine.GetAllWords();

            for (int i = 0; i < words.Length; i++)
                m_words_richTextBox.AppendText(words[i]+"\n");

        }

        private void refreshToolStripMenuItem1_Click(object sender, EventArgs e)
        {
            if (m_Engine.GenerateDotCode())
                refreshPicture();
        }

        private void m_containsWord_textBox_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode != Keys.Enter)
                return;

            if (m_containsWord_textBox.Text.Length == 0)
                return;

            if (m_Engine.ContainsWord(m_containsWord_textBox.Text))
                m_containsWord_textBox.BackColor = Color.LightGreen;
            else
                m_containsWord_textBox.BackColor = Color.Red;
        }

        private void m_containsWord_textBox_TextChanged(object sender, EventArgs e)
        {
            if (m_containsWord_textBox.BackColor != Color.White)
                m_containsWord_textBox.BackColor = Color.White;
        }

        private void m_presentation_textBox_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode != Keys.Enter)
                return;

            if (m_presentation_textBox.Text == "")
                return;

            int id = -1;

            if (radioButton1.Checked)
                id = 0;

            else if (radioButton2.Checked)
                id = 1;

            else if (radioButton3.Checked)
                id = 2;

            if (id >= 0)
                if (m_Engine.GenerateDotCode(m_presentation_textBox.Text, (uint) id))
                    refreshPicture();
        }

        private void loadToolStripMenuItem_Click(object sender, EventArgs e)
        {
            OpenFileDialog openFileDialog1 = new OpenFileDialog();
            openFileDialog1.InitialDirectory = m_binPath;
            openFileDialog1.Title = "Browse Text Files";
            openFileDialog1.DefaultExt = "txt";
            openFileDialog1.Filter = "txt files (*.txt)|*.txt|All files (*.*)|*.*";
            openFileDialog1.CheckFileExists = true;
            openFileDialog1.CheckPathExists = true;
            openFileDialog1.Multiselect = false;

            if (openFileDialog1.ShowDialog() == DialogResult.OK)
            {
                string str = openFileDialog1.FileName;

                if (m_Engine.LoadKeysFromFile(str))
                    m_numOfWords_StatusLabel.Text = m_Engine.Size().ToString();
            }
        }

        private void refreshPicture()
        {
            string dataPath = m_binPath + "\\data";
            string dotFile = dataPath + "\\dot.txt";
            string args = "dot -Tpng \"" + dotFile + "\" -o \"" + dataPath + "\\TST.png\"";

            string s = Environment.GetEnvironmentVariable("GRAPHVIZ_DOT");
            ProcessStartInfo startInfo = new ProcessStartInfo(s);
            startInfo.Arguments = args;
            startInfo.WindowStyle = ProcessWindowStyle.Hidden;

            if (m_pictureBox.Image != null)
                m_pictureBox.Image.Dispose();

            Process p = Process.Start(startInfo);

            p.WaitForExit();

            Bitmap image = new Bitmap("..\\..\\data\\TST.png");
            m_pictureBox.Image = image;
        }

    }
}
