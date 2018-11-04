using System;
using System.Web;
using System.Web.UI;

namespace ListBox
{

    public partial class Default : System.Web.UI.Page
    {
        public void AddItem(object sender, EventArgs args)
        {
            for (int i = 0; i < drop1.Items.Count; i++){
                if(drop1.Items[i].Selected){
                    string strText = drop1.Items[i].Text;
                    drop2.Items.Add(strText);
                    drop1.Items.RemoveAt(i);
                }
            }
        }
        public void RemoveItem(object sender, EventArgs args){
            for (int i = 0; i < drop2.Items.Count; i++)
            {
                if (drop2.Items[i].Selected)
                {
                    string strText = drop2.Items[i].Text;
                    drop1.Items.Add(strText);
                    drop2.Items.RemoveAt(i);
                }
            }
        }
    }
}
