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

namespace _08_INotyfyPropertChanged_PropertyChanged
{
    /// <summary>
    /// MainWindow.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
            ViewModel viewModel = new ViewModel();
            DataContext = viewModel;
        }

        private void btn1_Click(object sender, RoutedEventArgs e)
        {
            ViewModel viewModel = DataContext as ViewModel;
            MessageBox.Show(viewModel.LASTNAME +" " + viewModel.FIRSTNAME);

        }

        private void btn2_Click(object sender, RoutedEventArgs e)
        {
            ViewModel viewModel = DataContext as ViewModel;
            viewModel.FIRSTNAME = "선민";
            viewModel.LASTNAME = "이";
        }
    }
}
