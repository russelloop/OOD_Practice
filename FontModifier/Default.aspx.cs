using System;
using System.Web;
using System.Web.UI;

namespace FontModifier
{

    public partial class Default : System.Web.UI.Page
    {

        protected void RBChanged1(object sender, EventArgs e){
            if (RadioButton1.Checked == true){
                ShowText.ForeColor = System.Drawing.Color.Green;
            }
        }

        protected void RBLChanged1(object sender, EventArgs e){

            if (RadioButtonList.SelectedValue == "1"){
                ShowText.ForeColor = System.Drawing.Color.Red;
            }
            if (RadioButtonList.SelectedValue == "2"){
                ShowText.ForeColor = System.Drawing.Color.Blue;
            }
            if  (RadioButtonList.SelectedValue == "3"){
                ShowText.ForeColor = System.Drawing.Color.Yellow;
            }

        }

        protected void CBChanged1(object sender, EventArgs e){
            if(CheckBox.Checked == true){
                ShowText.Font.Underline = true;
            }
            else
                ShowText.Font.Underline = false;
        }

        protected void CBLChanged1(object sender, EventArgs e){
            if (CheckBoxList1.Items[0].Selected == true){
                ShowText.Font.Bold = true;

            }

            if (CheckBoxList1.Items[1].Selected == true){
                ShowText.Font.Italic = true;
            }
        }
    }
}
