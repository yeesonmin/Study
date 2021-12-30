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

namespace _03_MVVVM_LiveChart.View
{
    /// <summary>
    /// View_PieChart.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class View_PieChart : UserControl
    {
        public View_PieChart()
        {
            InitializeComponent();
        }

        private void Chart_OnDataClick(object sender, LiveCharts.ChartPoint chartPoint)
        {

        }
    }
}
