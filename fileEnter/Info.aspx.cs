using System;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
namespace fileEnter
{
    public partial class Info : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if (Session["name"] != null){
                string Name = Session["name"].ToString();
                Response.Write("Name: " + Name + "</br>");
            }
            if (Session["age"] != null){
                string Age = Session["age"].ToString();
                Response.Write("Age: " + Age + "</br>");
            }
            if (Session["sex"] != null){
                string Sex = Session["sex"].ToString();
                Response.Write("Sex: " + Sex + "</br>");
            }
            if (Session["city"] != null){
                string City = Session["city"].ToString();
                Response.Write("City: " + City + "</br>");
            }
            if (Session["address"] != null){
                string Address = Session["address"].ToString();
                Response.Write("Address: " + Address + "</br>");
            }
        }
    }
}
