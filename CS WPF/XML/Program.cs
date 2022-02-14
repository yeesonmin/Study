using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Linq;

namespace XML
{
    internal class Program
    {
        static void Main(string[] args)
        {
            //쓰기
            XDocument xdoc = new XDocument(new XDeclaration("1.0", "UTF-16", null));
            XElement xroot = new XElement("Employees");
            xdoc.Add(xroot);

            XElement xe1 = new XElement("Employee",
                new XAttribute("Id", "1001"),
                new XElement("Name", "Tim"),
                new XElement("Dept", "Sales")
            );

            XElement xe2 = new XElement("Employee",
                new XAttribute("Id", "1002"),
                new XElement("Name", "John"),
                new XElement("Dept", "HR")
            );

            xroot.Add(xe1);
            xroot.Add(xe2);

            xdoc.Save(@"..\Emp.xml");



            //읽기
            XDocument xdoc2 = XDocument.Load(@"..\Emp.xml");

            // <Employees> 노드 하나 리턴
            IEnumerable<XElement> elems = xdoc2.Elements();

            // 복수 개의 <Employee> 노드들 리턴
            IEnumerable<XElement> emps = xdoc2.Root.Elements();
            foreach (var emp in emps)
            {
                string id = emp.Attribute("Id").Value;
                string name = emp.Element("Name").Value;
                string dept = emp.Element("Dept").Value;

                Console.WriteLine(id + "," + name + "," + dept);
            }



            //LINQ
            XElement xElem = XElement.Load(@"..\Emp.xml");

            // Id가 1002인 Employee 검색
            var result = from xe in xElem.Elements("Employee")
                         where xe.Attribute("Id").Value == "1002"
                         select xe;

            var emp2 = result.SingleOrDefault();
            if (emp2 != null)
            {
                string name = emp2.Element("Name").Value;
                string dept = emp2.Element("Dept").Value;
                Console.WriteLine("{0},{1}", name, dept);
            }

            // Id가 1000 보다 큰 Employee들 검색
            var emps2 = from xe in xElem.Elements("Employee")
                       where int.Parse(xe.Attribute("Id").Value) > 1000
                       select xe;

            foreach (var e in emps2)
            {
                Console.WriteLine(e);
            }

            // LINQ 메서드 방식
            var empList = xElem.Elements("Employee").Where(p => p.Element("Name").Value == "Tim");
            foreach (var e in empList)
            {
                Console.WriteLine(e);
            }

        }
    }
}
