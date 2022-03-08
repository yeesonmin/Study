using _11_3D.Command;
using _11_3D.Model;
using _3DTools;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.ComponentModel;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Controls;
using System.Windows.Media;
using System.Windows.Media.Media3D;

namespace _11_3D.ViewModel
{
    internal class ViewModel_3DView : INotifyPropertyChanged
    {
        ObservableCollection<Model_3DView_Button> btnset;
        double farplanedistance = 100;
        double nearplanedistance = 1;
        double fieldofview = 70;
        double lookdirection_x = -11;
        double lookdirection_y = -10;
        double lookdirection_z = -9;
        double position_x = 11;
        double position_y = 10;
        double position_z = 9;
        bool show_wireframe = false;
        #region Property
        public ObservableCollection<Model_3DView_Button> BTNSET
        {
            get { return btnset; }
            set
            {
                btnset = value;
                OnPropertyChanged();
            }
        }

        public double FarPlaneDistance { get { return farplanedistance; } set { farplanedistance = value; CameraSetChange(); OnPropertyChanged(); } }
        public double NearPlaneDistance { get { return nearplanedistance; } set { nearplanedistance = value; CameraSetChange(); OnPropertyChanged(); } }
        public double FieldOfView { get { return fieldofview; } set { fieldofview = value; CameraSetChange(); OnPropertyChanged(); } }
        public double LookDirection_X { get { return lookdirection_x; } set { lookdirection_x = value; CameraSetChange(); OnPropertyChanged(); } }
        public double LookDirection_Y { get { return lookdirection_y; } set { lookdirection_y = value; CameraSetChange(); OnPropertyChanged(); } }
        public double LookDirection_Z { get { return lookdirection_z; } set { lookdirection_z = value; CameraSetChange(); OnPropertyChanged(); } }
        public double Position_X { get { return position_x; } set { position_x = value; CameraSetChange(); OnPropertyChanged(); } }
        public double Position_Y { get { return position_y; } set { position_y = value; CameraSetChange(); OnPropertyChanged(); } }
        public double Position_Z { get { return position_z; } set { position_z = value; CameraSetChange(); OnPropertyChanged(); } }

        public bool Show_Wireframe { get { return show_wireframe; } set { show_wireframe = value; OnPropertyChanged(); } }
        #endregion

        public ViewModel_3DView()
        {
            BTNSET = new ObservableCollection<Model_3DView_Button>();

            BTNSET.Add(new Model_3DView_Button() { BTN_Content = "Sample", BTN_COM = new RelayCommand(Sample) });
            BTNSET.Add(new Model_3DView_Button() { BTN_Content = "Draw Line", BTN_COM = new RelayCommand(DrawLine) });
            BTNSET.Add(new Model_3DView_Button() { BTN_Content = "Cube", BTN_COM = new RelayCommand(Cube) });
            BTNSET.Add(new Model_3DView_Button() { BTN_Content = "cylinder", BTN_COM = new RelayCommand(cylinder) });
            BTNSET.Add(new Model_3DView_Button() { BTN_Content = "Topography", BTN_COM = new RelayCommand(topography) });
            CameraSetting();
            LightSetting();
        }

        void CameraSetting()
        {
            PerspectiveCamera myPCamera = new PerspectiveCamera();
            myPCamera.FarPlaneDistance = 100;
            myPCamera.LookDirection = new Vector3D(-11, -10, -9);
            myPCamera.UpDirection = new Vector3D(0, 1, 0);
            myPCamera.NearPlaneDistance = 1;
            myPCamera.Position = new Point3D(11, 10, 9);
            myPCamera.FieldOfView = 70;

            Model_3DView.viewport3D.Camera = myPCamera;
        }

        void CameraSetChange()
        {
            PerspectiveCamera myPCamera = new PerspectiveCamera();
            myPCamera.FarPlaneDistance = FarPlaneDistance;
            myPCamera.LookDirection = new Vector3D(LookDirection_X, LookDirection_Y, LookDirection_Z);
            myPCamera.UpDirection = new Vector3D(0, 1, 0);
            myPCamera.NearPlaneDistance = NearPlaneDistance;
            myPCamera.Position = new Point3D(Position_X, Position_Y, Position_Z);
            myPCamera.FieldOfView = FieldOfView;

            Model_3DView.viewport3D.Camera = myPCamera;
        }

        void LightSetting()
        {
            DirectionalLight myDirectionalLight = new DirectionalLight();

            myDirectionalLight.Color = Colors.White;

            myDirectionalLight.Direction = new Vector3D(-2, -3, -1);

            ModelVisual3D model = new ModelVisual3D();
            model.Content = myDirectionalLight;

            Model_3DView.viewport3D.Children.Add(model);
        }

        void Sample(object obj)
        {
            DeleteChildren();
            MeshGeometry3D triangleMesh = new MeshGeometry3D();
            Point3D point0 = new Point3D(0, 0, 0);
            Point3D point1 = new Point3D(5, 0, 0);
            Point3D point2 = new Point3D(0, 0, 5);
            triangleMesh.Positions.Add(point0);
            triangleMesh.Positions.Add(point1);
            triangleMesh.Positions.Add(point2);
            triangleMesh.TriangleIndices.Add(0);
            triangleMesh.TriangleIndices.Add(2);
            triangleMesh.TriangleIndices.Add(1);
            Vector3D normal = new Vector3D(0, 1, 0);
            triangleMesh.Normals.Add(normal);
            triangleMesh.Normals.Add(normal);
            triangleMesh.Normals.Add(normal);

            Material material = new DiffuseMaterial(new SolidColorBrush(Colors.DarkKhaki));
            GeometryModel3D triangleModel = new GeometryModel3D(triangleMesh, material);
            ModelVisual3D model = new ModelVisual3D();
            model.Content = triangleModel;

            Model_3DView.viewport3D.Children.Add(model);
        }

        void DrawLine(object obj)
        {
            DeleteChildren();
            Model3DGroup line = new Model3DGroup();
            Point3D p0 = new Point3D(0, 0, 0);
            Point3D p1 = new Point3D(10, 0, 0);
            Point3D p2 = new Point3D(10, 0.1, 0);
            Point3D p3 = new Point3D(0, 0.1, 0);

            line.Children.Add(CreateTriangleModel(p0, p1, p2));
            line.Children.Add(CreateTriangleModel(p0, p2, p3));

            ModelVisual3D model = new ModelVisual3D();
            model.Content = line;

            Model_3DView.viewport3D.Children.Add(model);
        }

        void cylinder(object obj)
        {
            DeleteChildren();
            Model3DGroup cube = new Model3DGroup();
            Point3D p0 = new Point3D(0, 0, 0);
            Point3D p1 = new Point3D(5, 0, 0);
            Point3D p2 = new Point3D(5, 0, 5);
            Point3D p3 = new Point3D(0, 0, 5);
            Point3D p4 = new Point3D(0, 5, 0);
            Point3D p5 = new Point3D(5, 5, 0);
            Point3D p6 = new Point3D(5, 5, 5);
            Point3D p7 = new Point3D(0, 5, 5);

            //front side triangles
            cube.Children.Add(CreateTriangleModel(p3, p2, p6));
            cube.Children.Add(CreateTriangleModel(p3, p6, p7));
            //right side triangles
            cube.Children.Add(CreateTriangleModel(p2, p1, p5));
            cube.Children.Add(CreateTriangleModel(p2, p5, p6));
            //back side triangles
            cube.Children.Add(CreateTriangleModel(p1, p0, p4));
            cube.Children.Add(CreateTriangleModel(p1, p4, p5));
            //left side triangles
            cube.Children.Add(CreateTriangleModel(p0, p3, p7));
            cube.Children.Add(CreateTriangleModel(p0, p7, p4));
            //top side triangles
            cube.Children.Add(CreateTriangleModel(p7, p6, p5));
            cube.Children.Add(CreateTriangleModel(p7, p5, p4));
            //bottom side triangles
            cube.Children.Add(CreateTriangleModel(p2, p3, p0));
            cube.Children.Add(CreateTriangleModel(p2, p0, p1));

            ModelVisual3D model = new ModelVisual3D();
            model.Content = cube;


            Model_3DView.viewport3D.Children.Add(model);
        }
        void Cube(object obj)
        {
            DeleteChildren();
            Model3DGroup cube = new Model3DGroup();
            Point3D p0 = new Point3D(0, 0, 0);
            Point3D p1 = new Point3D(5, 0, 0);
            Point3D p2 = new Point3D(5, 0, 5);
            Point3D p3 = new Point3D(0, 0, 5);
            Point3D p4 = new Point3D(0, 5, 0);
            Point3D p5 = new Point3D(5, 5, 0);
            Point3D p6 = new Point3D(5, 5, 5);
            Point3D p7 = new Point3D(0, 5, 5);

            //front side triangles
            cube.Children.Add(CreateTriangleModel(p3, p2, p6));
            cube.Children.Add(CreateTriangleModel(p3, p6, p7));
            //right side triangles
            cube.Children.Add(CreateTriangleModel(p2, p1, p5));
            cube.Children.Add(CreateTriangleModel(p2, p5, p6));
            //back side triangles
            cube.Children.Add(CreateTriangleModel(p1, p0, p4));
            cube.Children.Add(CreateTriangleModel(p1, p4, p5));
            //left side triangles
            cube.Children.Add(CreateTriangleModel(p0, p3, p7));
            cube.Children.Add(CreateTriangleModel(p0, p7, p4));
            //top side triangles
            cube.Children.Add(CreateTriangleModel(p7, p6, p5));
            cube.Children.Add(CreateTriangleModel(p7, p5, p4));
            //bottom side triangles
            cube.Children.Add(CreateTriangleModel(p2, p3, p0));
            cube.Children.Add(CreateTriangleModel(p2, p0, p1));

            ModelVisual3D model = new ModelVisual3D();
            model.Content = cube;

            
            Model_3DView.viewport3D.Children.Add(model);
        }

        void topography(object obj)
        {
            DeleteChildren();
            Model3DGroup topography = new Model3DGroup();
            Point3D[] points = GetRandomTopographyPoints();
            for (int z = 0; z <= 80; z = z + 10)
            {
                for (int x = 0; x < 9; x++)
                {
                    topography.Children.Add(CreateTriangleModel(points[x + z], points[x + z + 10], points[x + z + 1]));
                    topography.Children.Add(CreateTriangleModel(points[x + z + 1], points[x + z + 10], points[x + z + 11]));
                }
            }
            ModelVisual3D model = new ModelVisual3D();
            model.Content = topography;
            Model_3DView.viewport3D.Children.Add(model);
        }

        private Point3D[] GetRandomTopographyPoints()
        {
            //create a 10x10 topography.
            Point3D[] points = new Point3D[100];
            Random r = new Random();
            double y;
            double denom = 1000;
            int count = 0;
            for (int z = 0; z < 10; z++)
            {
                for (int x = 0; x < 10; x++)
                {
                    y = Convert.ToDouble(r.Next(1, 999)) / denom;
                    points[count] = new Point3D(x, y, z);
                    count += 1;
                }
            }
            return points;
        }


        /// <summary>
        /// mesh 를 포함하는 Model3DGroup을 생성
        /// </summary>
        /// <param name="p0"></param>
        /// <param name="p1"></param>
        /// <param name="p2"></param>
        /// <returns></returns>
        private Model3DGroup CreateTriangleModel(Point3D p0, Point3D p1, Point3D p2)
        {
            MeshGeometry3D mesh = new MeshGeometry3D();
            mesh.Positions.Add(p0);
            mesh.Positions.Add(p1);
            mesh.Positions.Add(p2);
            mesh.TriangleIndices.Add(0);
            mesh.TriangleIndices.Add(1);
            mesh.TriangleIndices.Add(2);
            Vector3D normal = CalculateNormal(p0, p1, p2);
            mesh.Normals.Add(normal); 
            mesh.Normals.Add(normal);
            mesh.Normals.Add(normal);
            Material material = new DiffuseMaterial(new SolidColorBrush(Colors.WhiteSmoke));
            GeometryModel3D model = new GeometryModel3D(mesh, material);
            Model3DGroup group = new Model3DGroup();
            group.Children.Add(model);

           if (Show_Wireframe == true)
            {
                //3DTools DLL 추가해야 함.
                ScreenSpaceLines3D wireframe = new ScreenSpaceLines3D();
                wireframe.Points.Add(p0);
                wireframe.Points.Add(p1);
                wireframe.Points.Add(p2);
                wireframe.Points.Add(p0);
                wireframe.Color = Colors.LightBlue;
                wireframe.Thickness = 3;
                Model_3DView.viewport3D.Children.Add(wireframe);
            }
            return group;
        }

        

        /// <summary>
        /// triangle index 의 법선을 구할 때 사용
        /// </summary>
        /// <param name="p0"></param>
        /// <param name="p1"></param>
        /// <param name="p2"></param>
        /// <returns></returns>
        private Vector3D CalculateNormal(Point3D p0, Point3D p1, Point3D p2)
        {
            Vector3D v0 = new Vector3D(p1.X - p0.X, p1.Y - p0.Y, p1.Z - p0.Z);
            Vector3D v1 = new Vector3D(p2.X - p1.X, p2.Y - p1.Y, p2.Z - p1.Z);
            return Vector3D.CrossProduct(v0, v1);
        }

        void DeleteChildren()
        {
            for (int i = Model_3DView.viewport3D.Children.Count - 1; i >= 1; i--)
            {
                Model_3DView.viewport3D.Children.RemoveAt(i);
            }
        }
        #region PropertyChanged
        public event PropertyChangedEventHandler PropertyChanged;
        private void OnPropertyChanged([CallerMemberName] string v = null)
        {
            if (PropertyChanged != null)
            {
                PropertyChanged(this, new PropertyChangedEventArgs(v));
            }
        }
        #endregion

    }
}
