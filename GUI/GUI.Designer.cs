namespace GUI
{
    partial class GUI
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.statusStrip1 = new System.Windows.Forms.StatusStrip();
            this.toolStripStatusLabel1 = new System.Windows.Forms.ToolStripStatusLabel();
            this.m_numOfWords_StatusLabel = new System.Windows.Forms.ToolStripStatusLabel();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.m_clear_button = new System.Windows.Forms.Button();
            this.m_manipulate_textbox = new System.Windows.Forms.TextBox();
            this.m_delete_button = new System.Windows.Forms.Button();
            this.m_insert_button = new System.Windows.Forms.Button();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.m_prefixSearch_comboBox = new System.Windows.Forms.ComboBox();
            this.label4 = new System.Windows.Forms.Label();
            this.m_containsWord_textBox = new System.Windows.Forms.TextBox();
            this.m_wordMatchSearch_comboBox = new System.Windows.Forms.ComboBox();
            this.label3 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.m_longestPrefixSearch_textBox = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.panel1 = new System.Windows.Forms.Panel();
            this.m_pictureBox = new System.Windows.Forms.PictureBox();
            this.contextMenuStrip2 = new System.Windows.Forms.ContextMenuStrip(this.components);
            this.refreshToolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
            this.groupBox3 = new System.Windows.Forms.GroupBox();
            this.m_words_richTextBox = new System.Windows.Forms.RichTextBox();
            this.contextMenuStrip1 = new System.Windows.Forms.ContextMenuStrip(this.components);
            this.refreshToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.fileToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.loadToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.groupBox4 = new System.Windows.Forms.GroupBox();
            this.radioButton3 = new System.Windows.Forms.RadioButton();
            this.radioButton2 = new System.Windows.Forms.RadioButton();
            this.radioButton1 = new System.Windows.Forms.RadioButton();
            this.label5 = new System.Windows.Forms.Label();
            this.m_presentation_textBox = new System.Windows.Forms.TextBox();
            this.statusStrip1.SuspendLayout();
            this.groupBox1.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.panel1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.m_pictureBox)).BeginInit();
            this.contextMenuStrip2.SuspendLayout();
            this.groupBox3.SuspendLayout();
            this.contextMenuStrip1.SuspendLayout();
            this.menuStrip1.SuspendLayout();
            this.groupBox4.SuspendLayout();
            this.SuspendLayout();
            // 
            // statusStrip1
            // 
            this.statusStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.toolStripStatusLabel1,
            this.m_numOfWords_StatusLabel});
            this.statusStrip1.Location = new System.Drawing.Point(0, 719);
            this.statusStrip1.Name = "statusStrip1";
            this.statusStrip1.Size = new System.Drawing.Size(1264, 22);
            this.statusStrip1.TabIndex = 0;
            this.statusStrip1.Text = "statusStrip1";
            // 
            // toolStripStatusLabel1
            // 
            this.toolStripStatusLabel1.Name = "toolStripStatusLabel1";
            this.toolStripStatusLabel1.Size = new System.Drawing.Size(76, 17);
            this.toolStripStatusLabel1.Text = "Total Words: ";
            // 
            // m_numOfWords_StatusLabel
            // 
            this.m_numOfWords_StatusLabel.Name = "m_numOfWords_StatusLabel";
            this.m_numOfWords_StatusLabel.Size = new System.Drawing.Size(13, 17);
            this.m_numOfWords_StatusLabel.Text = "0";
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.m_clear_button);
            this.groupBox1.Controls.Add(this.m_manipulate_textbox);
            this.groupBox1.Controls.Add(this.m_delete_button);
            this.groupBox1.Controls.Add(this.m_insert_button);
            this.groupBox1.Location = new System.Drawing.Point(12, 27);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(181, 112);
            this.groupBox1.TabIndex = 1;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Insert / Delete";
            // 
            // m_clear_button
            // 
            this.m_clear_button.Location = new System.Drawing.Point(43, 74);
            this.m_clear_button.Name = "m_clear_button";
            this.m_clear_button.Size = new System.Drawing.Size(75, 23);
            this.m_clear_button.TabIndex = 3;
            this.m_clear_button.Text = "Clear Tree";
            this.m_clear_button.UseVisualStyleBackColor = true;
            this.m_clear_button.Click += new System.EventHandler(this.m_clear_button_Click);
            // 
            // m_manipulate_textbox
            // 
            this.m_manipulate_textbox.CharacterCasing = System.Windows.Forms.CharacterCasing.Lower;
            this.m_manipulate_textbox.Location = new System.Drawing.Point(17, 19);
            this.m_manipulate_textbox.Name = "m_manipulate_textbox";
            this.m_manipulate_textbox.Size = new System.Drawing.Size(131, 20);
            this.m_manipulate_textbox.TabIndex = 2;
            this.m_manipulate_textbox.KeyDown += new System.Windows.Forms.KeyEventHandler(this.m_manipulate_textbox_KeyDown);
            // 
            // m_delete_button
            // 
            this.m_delete_button.Location = new System.Drawing.Point(102, 45);
            this.m_delete_button.Name = "m_delete_button";
            this.m_delete_button.Size = new System.Drawing.Size(46, 23);
            this.m_delete_button.TabIndex = 1;
            this.m_delete_button.Text = "Delete";
            this.m_delete_button.UseVisualStyleBackColor = true;
            this.m_delete_button.Click += new System.EventHandler(this.m_delete_button_Click);
            // 
            // m_insert_button
            // 
            this.m_insert_button.Location = new System.Drawing.Point(17, 45);
            this.m_insert_button.Name = "m_insert_button";
            this.m_insert_button.Size = new System.Drawing.Size(45, 23);
            this.m_insert_button.TabIndex = 0;
            this.m_insert_button.Text = "Insert";
            this.m_insert_button.UseVisualStyleBackColor = true;
            this.m_insert_button.Click += new System.EventHandler(this.m_insert_button_Click);
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.m_prefixSearch_comboBox);
            this.groupBox2.Controls.Add(this.label4);
            this.groupBox2.Controls.Add(this.m_containsWord_textBox);
            this.groupBox2.Controls.Add(this.m_wordMatchSearch_comboBox);
            this.groupBox2.Controls.Add(this.label3);
            this.groupBox2.Controls.Add(this.label2);
            this.groupBox2.Controls.Add(this.m_longestPrefixSearch_textBox);
            this.groupBox2.Controls.Add(this.label1);
            this.groupBox2.Location = new System.Drawing.Point(12, 145);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(181, 214);
            this.groupBox2.TabIndex = 2;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Search Word";
            // 
            // m_prefixSearch_comboBox
            // 
            this.m_prefixSearch_comboBox.FormattingEnabled = true;
            this.m_prefixSearch_comboBox.Location = new System.Drawing.Point(9, 49);
            this.m_prefixSearch_comboBox.Name = "m_prefixSearch_comboBox";
            this.m_prefixSearch_comboBox.Size = new System.Drawing.Size(135, 21);
            this.m_prefixSearch_comboBox.TabIndex = 9;
            this.m_prefixSearch_comboBox.TextChanged += new System.EventHandler(this.m_prefixSearch_comboBox_TextChanged);
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(10, 162);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(122, 13);
            this.label4.TabIndex = 8;
            this.label4.Text = "Contains word (on enter)";
            // 
            // m_containsWord_textBox
            // 
            this.m_containsWord_textBox.Location = new System.Drawing.Point(9, 178);
            this.m_containsWord_textBox.Name = "m_containsWord_textBox";
            this.m_containsWord_textBox.Size = new System.Drawing.Size(135, 20);
            this.m_containsWord_textBox.TabIndex = 7;
            this.m_containsWord_textBox.TextChanged += new System.EventHandler(this.m_containsWord_textBox_TextChanged);
            this.m_containsWord_textBox.KeyDown += new System.Windows.Forms.KeyEventHandler(this.m_containsWord_textBox_KeyDown);
            // 
            // m_wordMatchSearch_comboBox
            // 
            this.m_wordMatchSearch_comboBox.FormattingEnabled = true;
            this.m_wordMatchSearch_comboBox.Location = new System.Drawing.Point(9, 92);
            this.m_wordMatchSearch_comboBox.Name = "m_wordMatchSearch_comboBox";
            this.m_wordMatchSearch_comboBox.Size = new System.Drawing.Size(135, 21);
            this.m_wordMatchSearch_comboBox.TabIndex = 6;
            this.m_wordMatchSearch_comboBox.TextChanged += new System.EventHandler(this.m_wordMatchSearch_comboBox_TextChanged);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(10, 76);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(91, 13);
            this.label3.TabIndex = 5;
            this.label3.Text = "Words that match";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(10, 120);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(159, 13);
            this.label2.TabIndex = 3;
            this.label2.Text = "Longest prefix of word (on enter)";
            // 
            // m_longestPrefixSearch_textBox
            // 
            this.m_longestPrefixSearch_textBox.AutoCompleteSource = System.Windows.Forms.AutoCompleteSource.CustomSource;
            this.m_longestPrefixSearch_textBox.CharacterCasing = System.Windows.Forms.CharacterCasing.Lower;
            this.m_longestPrefixSearch_textBox.Location = new System.Drawing.Point(9, 136);
            this.m_longestPrefixSearch_textBox.Name = "m_longestPrefixSearch_textBox";
            this.m_longestPrefixSearch_textBox.Size = new System.Drawing.Size(135, 20);
            this.m_longestPrefixSearch_textBox.TabIndex = 2;
            this.m_longestPrefixSearch_textBox.TextChanged += new System.EventHandler(this.m_longestPrefixSearch_textBox_TextChanged);
            this.m_longestPrefixSearch_textBox.KeyDown += new System.Windows.Forms.KeyEventHandler(this.m_longestPrefixSearch_textBox_KeyDown);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(14, 32);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(88, 13);
            this.label1.TabIndex = 1;
            this.label1.Text = "Words with prefix";
            // 
            // panel1
            // 
            this.panel1.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.panel1.AutoScroll = true;
            this.panel1.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.panel1.Controls.Add(this.m_pictureBox);
            this.panel1.Location = new System.Drawing.Point(209, 12);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(1043, 704);
            this.panel1.TabIndex = 3;
            // 
            // m_pictureBox
            // 
            this.m_pictureBox.BackColor = System.Drawing.SystemColors.Control;
            this.m_pictureBox.ContextMenuStrip = this.contextMenuStrip2;
            this.m_pictureBox.Location = new System.Drawing.Point(3, 3);
            this.m_pictureBox.Name = "m_pictureBox";
            this.m_pictureBox.Size = new System.Drawing.Size(1033, 703);
            this.m_pictureBox.SizeMode = System.Windows.Forms.PictureBoxSizeMode.AutoSize;
            this.m_pictureBox.TabIndex = 0;
            this.m_pictureBox.TabStop = false;
            // 
            // contextMenuStrip2
            // 
            this.contextMenuStrip2.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.refreshToolStripMenuItem1});
            this.contextMenuStrip2.Name = "contextMenuStrip2";
            this.contextMenuStrip2.Size = new System.Drawing.Size(114, 26);
            // 
            // refreshToolStripMenuItem1
            // 
            this.refreshToolStripMenuItem1.Name = "refreshToolStripMenuItem1";
            this.refreshToolStripMenuItem1.Size = new System.Drawing.Size(113, 22);
            this.refreshToolStripMenuItem1.Text = "Refresh";
            this.refreshToolStripMenuItem1.Click += new System.EventHandler(this.refreshToolStripMenuItem1_Click);
            // 
            // groupBox3
            // 
            this.groupBox3.Controls.Add(this.m_words_richTextBox);
            this.groupBox3.Location = new System.Drawing.Point(12, 365);
            this.groupBox3.Name = "groupBox3";
            this.groupBox3.Size = new System.Drawing.Size(181, 195);
            this.groupBox3.TabIndex = 4;
            this.groupBox3.TabStop = false;
            this.groupBox3.Text = "Words";
            // 
            // m_words_richTextBox
            // 
            this.m_words_richTextBox.ContextMenuStrip = this.contextMenuStrip1;
            this.m_words_richTextBox.DetectUrls = false;
            this.m_words_richTextBox.Location = new System.Drawing.Point(9, 19);
            this.m_words_richTextBox.Name = "m_words_richTextBox";
            this.m_words_richTextBox.ReadOnly = true;
            this.m_words_richTextBox.Size = new System.Drawing.Size(166, 170);
            this.m_words_richTextBox.TabIndex = 0;
            this.m_words_richTextBox.Text = "";
            // 
            // contextMenuStrip1
            // 
            this.contextMenuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.refreshToolStripMenuItem});
            this.contextMenuStrip1.Name = "contextMenuStrip1";
            this.contextMenuStrip1.Size = new System.Drawing.Size(114, 26);
            // 
            // refreshToolStripMenuItem
            // 
            this.refreshToolStripMenuItem.Name = "refreshToolStripMenuItem";
            this.refreshToolStripMenuItem.Size = new System.Drawing.Size(113, 22);
            this.refreshToolStripMenuItem.Text = "Refresh";
            this.refreshToolStripMenuItem.Click += new System.EventHandler(this.refreshToolStripMenuItem_Click);
            // 
            // menuStrip1
            // 
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.fileToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(1264, 24);
            this.menuStrip1.TabIndex = 5;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // fileToolStripMenuItem
            // 
            this.fileToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.loadToolStripMenuItem});
            this.fileToolStripMenuItem.Name = "fileToolStripMenuItem";
            this.fileToolStripMenuItem.Size = new System.Drawing.Size(37, 20);
            this.fileToolStripMenuItem.Text = "File";
            // 
            // loadToolStripMenuItem
            // 
            this.loadToolStripMenuItem.Name = "loadToolStripMenuItem";
            this.loadToolStripMenuItem.Size = new System.Drawing.Size(100, 22);
            this.loadToolStripMenuItem.Text = "Load";
            this.loadToolStripMenuItem.Click += new System.EventHandler(this.loadToolStripMenuItem_Click);
            // 
            // groupBox4
            // 
            this.groupBox4.Controls.Add(this.radioButton3);
            this.groupBox4.Controls.Add(this.radioButton2);
            this.groupBox4.Controls.Add(this.radioButton1);
            this.groupBox4.Controls.Add(this.label5);
            this.groupBox4.Controls.Add(this.m_presentation_textBox);
            this.groupBox4.Location = new System.Drawing.Point(12, 566);
            this.groupBox4.Name = "groupBox4";
            this.groupBox4.Size = new System.Drawing.Size(181, 157);
            this.groupBox4.TabIndex = 6;
            this.groupBox4.TabStop = false;
            this.groupBox4.Text = "Graph Presentation";
            // 
            // radioButton3
            // 
            this.radioButton3.AutoSize = true;
            this.radioButton3.Location = new System.Drawing.Point(7, 121);
            this.radioButton3.Name = "radioButton3";
            this.radioButton3.Size = new System.Drawing.Size(129, 17);
            this.radioButton3.TabIndex = 4;
            this.radioButton3.TabStop = true;
            this.radioButton3.Text = "Longest prefix of word";
            this.radioButton3.UseVisualStyleBackColor = true;
            // 
            // radioButton2
            // 
            this.radioButton2.AutoSize = true;
            this.radioButton2.Location = new System.Drawing.Point(7, 97);
            this.radioButton2.Name = "radioButton2";
            this.radioButton2.Size = new System.Drawing.Size(109, 17);
            this.radioButton2.TabIndex = 3;
            this.radioButton2.TabStop = true;
            this.radioButton2.Text = "Words that match";
            this.radioButton2.UseVisualStyleBackColor = true;
            // 
            // radioButton1
            // 
            this.radioButton1.AutoSize = true;
            this.radioButton1.Location = new System.Drawing.Point(7, 74);
            this.radioButton1.Name = "radioButton1";
            this.radioButton1.Size = new System.Drawing.Size(106, 17);
            this.radioButton1.TabIndex = 2;
            this.radioButton1.TabStop = true;
            this.radioButton1.Text = "Words with prefix";
            this.radioButton1.UseVisualStyleBackColor = true;
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(14, 29);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(108, 13);
            this.label5.TabIndex = 1;
            this.label5.Text = "Input Word (on enter)";
            // 
            // m_presentation_textBox
            // 
            this.m_presentation_textBox.Location = new System.Drawing.Point(10, 46);
            this.m_presentation_textBox.Name = "m_presentation_textBox";
            this.m_presentation_textBox.Size = new System.Drawing.Size(135, 20);
            this.m_presentation_textBox.TabIndex = 0;
            this.m_presentation_textBox.KeyDown += new System.Windows.Forms.KeyEventHandler(this.m_presentation_textBox_KeyDown);
            // 
            // GUI
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1264, 741);
            this.Controls.Add(this.groupBox4);
            this.Controls.Add(this.groupBox3);
            this.Controls.Add(this.panel1);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.statusStrip1);
            this.Controls.Add(this.menuStrip1);
            this.MainMenuStrip = this.menuStrip1;
            this.Name = "GUI";
            this.Text = "Ternary Search Tree";
            this.statusStrip1.ResumeLayout(false);
            this.statusStrip1.PerformLayout();
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            this.panel1.ResumeLayout(false);
            this.panel1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.m_pictureBox)).EndInit();
            this.contextMenuStrip2.ResumeLayout(false);
            this.groupBox3.ResumeLayout(false);
            this.contextMenuStrip1.ResumeLayout(false);
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.groupBox4.ResumeLayout(false);
            this.groupBox4.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.StatusStrip statusStrip1;
        private System.Windows.Forms.ToolStripStatusLabel toolStripStatusLabel1;
        private System.Windows.Forms.ToolStripStatusLabel m_numOfWords_StatusLabel;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.TextBox m_manipulate_textbox;
        private System.Windows.Forms.Button m_delete_button;
        private System.Windows.Forms.Button m_insert_button;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.PictureBox m_pictureBox;
        private System.Windows.Forms.Button m_clear_button;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox m_longestPrefixSearch_textBox;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.ComboBox m_wordMatchSearch_comboBox;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.GroupBox groupBox3;
        private System.Windows.Forms.RichTextBox m_words_richTextBox;
        private System.Windows.Forms.ContextMenuStrip contextMenuStrip1;
        private System.Windows.Forms.ToolStripMenuItem refreshToolStripMenuItem;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.TextBox m_containsWord_textBox;
        private System.Windows.Forms.ComboBox m_prefixSearch_comboBox;
        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem fileToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem loadToolStripMenuItem;
        private System.Windows.Forms.ContextMenuStrip contextMenuStrip2;
        private System.Windows.Forms.ToolStripMenuItem refreshToolStripMenuItem1;
        private System.Windows.Forms.GroupBox groupBox4;
        private System.Windows.Forms.RadioButton radioButton3;
        private System.Windows.Forms.RadioButton radioButton2;
        private System.Windows.Forms.RadioButton radioButton1;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.TextBox m_presentation_textBox;
    }
}

