﻿using LiveCharts;
using LiveCharts.Defaults;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;

namespace _03_MVVVM_LiveChart.ViewModel
{
    class ViewModel_ScatterPlot : UserControl
    {
        public ViewModel_ScatterPlot()
        {
            var r = new Random();
            ValuesA = new ChartValues<ObservablePoint>();
            ValuesB = new ChartValues<ObservablePoint>();
            ValuesC = new ChartValues<ObservablePoint>();

            for (var i = 0; i < 20; i++)
            {
                ValuesA.Add(new ObservablePoint(r.NextDouble() * 10, r.NextDouble() * 10));
                ValuesB.Add(new ObservablePoint(r.NextDouble() * 10, r.NextDouble() * 10));
                ValuesC.Add(new ObservablePoint(r.NextDouble() * 10, r.NextDouble() * 10));
            }
        }
        public ChartValues<ObservablePoint> ValuesA { get; set; }
        public ChartValues<ObservablePoint> ValuesB { get; set; }
        public ChartValues<ObservablePoint> ValuesC { get; set; }

        private void RandomizeOnClick(object sender, RoutedEventArgs e)
        {
            var r = new Random();
            for (var i = 0; i < 20; i++)
            {
                ValuesA[i].X = r.NextDouble() * 10;
                ValuesA[i].Y = r.NextDouble() * 10;
                ValuesB[i].X = r.NextDouble() * 10;
                ValuesB[i].Y = r.NextDouble() * 10;
                ValuesC[i].X = r.NextDouble() * 10;
                ValuesC[i].Y = r.NextDouble() * 10;
            }
        }
    }
}
