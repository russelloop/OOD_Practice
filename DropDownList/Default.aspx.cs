using System;
using System.Web;
using System.Web.UI;

namespace DropDownList
{

    public partial class Default : System.Web.UI.Page
    {
        public void Page_Load(object sender, EventArgs args){
            if (!IsPostBack){
                DDL1Origin();
            }
            else{
                DDL1Changed();
            }
        }
        public void DDL1Origin(){
            DDList2.Items.Add("https://outlook.live.com/owa");
            DDList2.Items.Add("https://login.yahoo.com");
            DDList2.Items.Add("https://mail.google.co");
        }

        public void DDL1Changed(){
            if(DDList1.SelectedValue == "2"){
                DDList2.Items.Clear();
                DDList2.Items.Add("https://www.baidu.com");
                DDList2.Items.Add("https://www.google.com");
                DDList2.Items.Add("https://cn.bing.com");
            }
            else if(DDList1.SelectedValue == "3"){
                DDList2.Items.Clear();
                DDList2.Items.Add("http://www.xinhuanet.com");
                DDList2.Items.Add("https://www.thepaper.cn");
                DDList2.Items.Add("https://news.163.com");
            }
        }
    }
}
