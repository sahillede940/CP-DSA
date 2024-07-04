using System; 
using System.IO; 
using System.Net.Http;
using System.Collections.Generic;
using System.Threading.Tasks;
using Newtonsoft.Json;

public
class MainClass {
  static async Task Main() {
    HttpClient client = new HttpClient();
    string s = await client.GetStringAsync("https://coderbyte.com/api/challenges/json/age-counting");
    Console.WriteLine(s);
    int countOver50 = ProcessAndCountAges(s);
    Console.WriteLine(countOver50);
    string token = "as2134s";
    string ans = countOver50.ToString() + token;
    // add '_' at every 4th character
    string result = "";
    for (int i = 0; i < ans.Length; i++) {
      if (i % 4 == 0 && i != 0)
       {
        result += "_";
      }else {
        result += ans[i];
      }
    }
  
  } 

  static int ProcessAndCountAges(string jsonString) {
    int count = 0;
    dynamic data = JsonConvert.DeserializeObject(jsonString);
    string[] pairs = data.data.Split(',');
    foreach (string pair in pairs) {
      string[] parts = pair.Split('=');
      if (parts[0].Trim() == "age") {
        int age = int.Parse(parts[1]);
        if (age >= 50) {
          count++;
        }
      }
    }
    return count;
  }

}