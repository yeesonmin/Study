using _11_3D.Model;
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

namespace _11_3D.View
{
    /// <summary>
    /// View_3DView.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class View_3DView : UserControl
    {
        public View_3DView()
        {
            InitializeComponent();
            Model_3DView.viewport3D = view3d;
        }
    }
}
