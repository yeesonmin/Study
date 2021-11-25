using _04_Data_Binding.ViewModel;
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

namespace _04_Data_Binding
{
    /// <summary>
    /// MainWindow.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class MainWindow : Window
    {
        internal static Duties duties = new Duties();
        public MainWindow()
        {
            InitializeComponent();
        }

        private void ltb1_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            if((sender as ListBox).SelectedItem != null)
            {
                string dutyType = ((sender as ListBox).SelectedItem as ListBoxItem).Content.ToString();

                DataContext = from duty in duties
                              where duty.DutyType.ToString() == dutyType
                              select duty;
            }
        }

        private void ltb2_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            var duty = (Duty)ltb2.SelectedItem;
            MessageBox.Show(duty.DutyName + "::" + duty.DutyType, "선택한 직무 타입");
        }

        private void OpenNewWindow(object sender, RoutedEventArgs e)
        {
            SubWindow subwindow = new SubWindow();
            RefreshListEvent += new RefreshList(RefreshListBox);
            subwindow.UpdateActor = RefreshListEvent;
            subwindow.Show();

        }

        public delegate void RefreshList(DutyType dutyType);
        public event RefreshList RefreshListEvent;
        private void RefreshListBox(DutyType dutyType)
        {
            ltb1.SelectedItem = null;
            ltb1.SelectedIndex = (dutyType == DutyType.Inner) ? 0 : 1;

        }
    }
}
