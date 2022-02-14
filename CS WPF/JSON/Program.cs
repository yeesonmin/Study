using Newtonsoft.Json;
using Newtonsoft.Json.Linq;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace JSON
{
    internal class Program
    {
        static void Main(string[] args)
        {
            //Json 직렬화
            var p = new Person { Id = 1, Name = "Alex" };
            string jsonString = JsonConvert.SerializeObject(p);
            Console.WriteLine(jsonString);

            //Json 역직렬화
            Person pObj = JsonConvert.DeserializeObject<Person>(jsonString);
            Console.WriteLine(pObj.Name);


            string str = @"{ 
            Id: 101,                
            Phone: ['010-123-3456', '02-2222-3333', '010-222-1121']
        }";

            // 예제 1 : LINQ to JSON
            // JSON 문자열을 파싱하여 JObject를 리턴
            JObject jo = JObject.Parse(str);

            // JObject 인덱서를 사용하여 특정 Token을 리턴
            JToken idToken = jo["Id"];
            int id = (int)idToken;
            string phone1 = jo["Phone"][0].ToString();
            Console.WriteLine("{0}:{1}", id, phone1);

            var cell = jo["Phone"].Select(x => x.ToString().StartsWith("010"));

            foreach (var item in cell)
            {
                Console.WriteLine(item.ToString());
            }

            // 예제 2 : dynamic 
            dynamic jobj = JsonConvert.DeserializeObject(str);
            var xid = jobj.Id.ToString();
            var xphone1 = jobj.Phone[1].ToString();
            Console.WriteLine("{0}:{1}", xid, xphone1);
        }
    }
}
