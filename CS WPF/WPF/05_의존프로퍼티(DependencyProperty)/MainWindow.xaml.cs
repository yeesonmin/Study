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

namespace _05_의존프로퍼티_DependencyProperty_
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

        public String MyColor
        {
            get { return (String)GetValue(MyProperty); }
            set { SetValue(MyProperty, value); }
        }

        public static readonly DependencyProperty MyProperty = DependencyProperty.Register(
            "MyColor",//의존속성을 갖을 속성
            typeof(String),//타입
            typeof(MainWindow),//속성을 갖고 있는 Ower
            new FrameworkPropertyMetadata(new PropertyChangedCallback(OnMyPropertyChange)));//값 변경시 호출할 메소드, 그 메소드에 인자값 전달


        private static void OnMyPropertyChange(DependencyObject d, DependencyPropertyChangedEventArgs e)
        {
            MainWindow win = d as MainWindow;

            SolidColorBrush brush = (SolidColorBrush)new BrushConverter().ConvertFromString(e.NewValue.ToString());
            win.Background = brush;
            win.txtbox.Text = e.NewValue.ToString();
        }

        private void ContextMenu_Click(object sender, RoutedEventArgs e)
        {
            string str = (e.Source as MenuItem).Header.ToString();
            MyColor = str;//값이 변함 => OnMyPropertyChange 실행
        }
    }
}
