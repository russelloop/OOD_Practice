using System;
using System.Web.UI.WebControls;

//TODO Session
//TODO counter
//TODO .
namespace simpleCaculator{

    public partial class Default : System.Web.UI.Page{
        int Operator_Type;
        double Final_Result;
        bool Operated;      //Judge whether a num button is Click after an operator
        bool FOP = true;
        protected void Page_Load(object sender, EventArgs e){
            if(IsPostBack){
                FOP = Convert.ToBoolean(Session["fop"]);
                Final_Result = Convert.ToDouble(Session["result"]);
                Operated = Convert.ToBoolean(Session["operated"]);
                Operator_Type = Convert.ToInt32(Session["operateType"]);
            }
        }
        protected void buttonNumClick(object sender, EventArgs e){
            if (Operated){              //clear the screen if the num button is click after an operator
                txtResult.Text = null;
                Operated = false;       //may not be nessesary since it will be reloaded
                Session["operated"] = Operated;
            }

            txtResult.Text += ((Button)sender).Text;
        }
        protected void buttonOperatorClick(object sender, EventArgs e){

            string Operator = ((Button)sender).Text;
            if(!FOP){
                if(Operator_Type == 1)
                    Final_Result += Convert.ToDouble(txtResult.Text);
                if (Operator_Type == 2)
                    Final_Result -= Convert.ToDouble(txtResult.Text);
                if (Operator_Type == 3)
                    Final_Result *= Convert.ToDouble(txtResult.Text);
                if (Operator_Type == 4)
                    Final_Result /= Convert.ToDouble(txtResult.Text);
            }
            else
                Final_Result += Convert.ToDouble(txtResult.Text);

            if (Operator == "+")
                Operator_Type = 1;
            else if (Operator == "-")
                Operator_Type = 2;
            else if (Operator == "*")
                Operator_Type = 3;
            else if (Operator == "/")
                Operator_Type = 4;

            Operated = true;
            FOP = false;
            Session["fop"] = FOP;
            Session["operated"] = Operated;
            Session["result"] = Final_Result;
            Session["operateType"] = Operator_Type;
            txtResult.Text = Final_Result.ToString();
        }
        protected void buttonEqualsClick(object sender, EventArgs e){

            if (Operator_Type == 1){
                Final_Result += Convert.ToDouble(txtResult.Text);
            }
            if (Operator_Type == 2){
                Final_Result -= Convert.ToDouble(txtResult.Text);
            }
            if (Operator_Type == 3){
                Final_Result *= Convert.ToDouble(txtResult.Text);
            }
            if (Operator_Type == 4){
                Final_Result /= Convert.ToDouble(txtResult.Text);
            }
            Session["result"] = Final_Result;
            txtResult.Text = Final_Result.ToString();
        }
        protected void buttonClearClick(object sender, EventArgs e){
            txtResult.Text = null;
            Final_Result = 0;
            Session["operated"] = false;
            Session["result"] = Final_Result;
        }
    }
}