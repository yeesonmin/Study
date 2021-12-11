using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace _07_DataBindling__xaml간_
{
    /// <summary>
    /// MainWindow.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class MainWindow : Window
    {
        public bool A { get; set; }
        public bool B { get; set; }
        public bool C { get; set; }
        public MainWindow()
        {
            InitializeComponent();
            DataContext = this;//winddow에 있는 모든 컨트롤들은 소스 속성을 바인딩 할 수 있다.
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            MessageBox.Show(string.Format("A : {0}, B : {1}, C : {2}", A, B, C)); 
        }
    }
}
