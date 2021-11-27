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

namespace _06_RoutedEvent
{
    /// <summary>
    /// MainWindow.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }

        #region bubble event(기본) => 하위객체부터 상위개체까지 이벤트가 실행 됨.
        //private void Window_Click(object sender, RoutedEventArgs e)
        //{
        //    tb3.Text = "bubble click window";
        //}

        //private void StackPanel_Click(object sender, RoutedEventArgs e)
        //{
        //    tb2.Text = "bubble click stack";
        //}

        //private void Button_Click(object sender, RoutedEventArgs e)
        //{
        //    tb1.Text = "button click";
        //    e.Handled = true; // 상위 객체에 이벤트 실행 방지
        //}
        #endregion

        #region 터널링 이벤트
        private void Window_PreviewMouseDown(object sender, MouseButtonEventArgs e)
        {
            MessageBox.Show("window");
        }
        #endregion

        private void StackPanel_PreviewMouseDown(object sender, MouseButtonEventArgs e)
        {
            MessageBox.Show("stack");
        }

        private void Button_PreviewMouseDown(object sender, MouseButtonEventArgs e)
        {
            MessageBox.Show("button");
        }
    }
}
