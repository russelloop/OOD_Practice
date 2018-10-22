using System;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace fileEnter{

    public partial class Default : System.Web.UI.Page{
        protected void Page_Load(object sender, EventArgs e){
            //if(IsPostBack){
            //    Response.Redirect("Info.aspx");
            //}

        }
        protected void Button1_Click(object sender, EventArgs e)
        {
            if (TextBox1.Text != null){
                Session["name"] = TextBox1.Text;
            }
            if (TextBox2.Text != null){
                Session["age"] = TextBox2.Text;
            }
            if (DropDownList1.SelectedValue != null){
                Session["sex"] = DropDownList1.SelectedValue;
            }
            if (TextBox3.Text != null){
                Session["city"] = TextBox3.Text;
            }
            if (TextBox4.Text != null){
                Session["address"] = TextBox4.Text;
            }
            Response.Redirect("Info.aspx");
        }
    }
}
