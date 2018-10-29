using System;
using System.Web;
using System.Web.UI;

namespace FontModifier
{

    public partial class Default : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e){
            if(IsPostBack){
                ShowText.Text = Convert.ToString(Session["inputText"]);
            }
        }
        protected void TBChanged (object sender, EventArgs e){
            Session["inputText"] = TextBox1.Text;
        }

        protected void RBChanged1(object sender, EventArgs e){
            ShowText.Style.Remove("color");
            if (RadioButton1.Checked == true){
                ShowText.Style.Add("color", "green");
            }
        }

        protected void RBLChanged1(object sender, EventArgs e){
            ShowText.Style.Remove("color");
            if (red.Selected == true){
                ShowText.Style.Add("color", "red");
            }
            if (blue.Selected == true){
                ShowText.Style.Add("color", "blue");
            }
            if (yellow.Selected == true){
                ShowText.Style.Add("color", "yellow");
            }
        }

        protected void CBChanged1(object sender, EventArgs e){

        }

        protected void CBLChanged1(object sender, EventArgs e){

        }
    }
}
