using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace bulls_and_cows
{
    public partial class Play : Form
    {

        public const int size = 3;
        private string comnum = "";

        public void Checknum(string num)
        {
            int strike = 0;
            int ball = 0;

            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    if (num[i] == comnum[j])
                    {
                        if (i == j) strike += 1;
                        else ball += 1;
                    }
                }
            }

            if (ball == 0 && strike == 0)
            {
                label1.Text = "out";
                listBox1.Items.Add(num + " : OUT");
            }
            else
            {
                if (strike == size)
                {
                    label1.Text = "정답입니다.";
                    MessageBox.Show("정답입니다.");
                }
                else
                {
                    label1.Text = "S : " + strike + " B : " + ball;
                    listBox1.Items.Add(num + " : " + label1.Text);
                }
            }
        }



        public Play()
        {
            InitializeComponent();
            for (int i = 0; i < 10; i++)
            {
                Button button = new Button()
                {
                    Text = i.ToString(),
                };
                button.Click += new EventHandler(Btn_Click);
                flowLayoutPanel1.Controls.Add(button);

            }


            Random random = new Random();

            string tmpstr = "0123456789";
            while (comnum.Length < 3)
            {
                int tmp = random.Next(0, tmpstr.Length); // 0 ~ 9
                comnum += tmpstr[tmp];
                tmpstr = tmpstr.Remove(tmp, 1);
            }

        }
        
        private void Button11_Click(object sender, EventArgs e)
        {
            if (output.Text.Length == size)
            {
                for (int i = 0; i < size; i++) 
                {
                    for (int j = 0; j < size; j++)
                    {
                        if (i == j) continue;
                        if (output.Text[i] == output.Text[j])
                        {
                            MessageBox.Show("숫자가 중복됩니다.");
                            output.Text = "0";
                            return;
                        }
                    }
                }
                Checknum(output.Text);
                output.Text = "0";
            }
            else
            {
                MessageBox.Show("숫자를 입력해주세요");
            }
        }
        
        void Btn_Click(object sender, EventArgs e)
        {
            Button btn = sender as Button;
            string num = btn.Text;
            if (output.Text == "0") output.Text = num;
            else output.Text += num;
            if (output.Text.Length == size + 1)
            {
                output.Text = output.Text.Remove(0, 1);
            }
        }
    }
}
