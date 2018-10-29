using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.IO;
namespace ImageSalon{
    public partial class Default : System.Web.UI.Page{

        protected void Page_Load(object sender, EventArgs e){
            if (!IsPostBack){
                showImage(Int32.Parse(pictureIndex.Value));
            }
        }
        protected string[] getImages(){
            string[] path = Directory.GetFiles(Request.PhysicalApplicationPath + "picture");
            return path;
        }
        protected void showImage(int i){
            string[] path = getImages();
            Image.ImageUrl = path[i].Substring(path[i].LastIndexOf(@"\") + 1).Replace("/Users/dashwood/Projects/ASP.NET/ImageSalon", "~");
            Image.Visible = true;
            pictureIndex.Value = i.ToString();
        }

        protected void LastPicButton_Click(object sender, EventArgs e){
            if (Int32.Parse(pictureIndex.Value) == 0)
                return;
            else{
                int i = Int32.Parse(pictureIndex.Value);
                i--;
                pictureIndex.Value = i.ToString();
            }
            showImage(Int32.Parse(pictureIndex.Value));
        }

        protected void NextPicButton_Click(object sender, EventArgs e){
            if (Int32.Parse(pictureIndex.Value) == getImages().Length - 1){
                return;
            }
            else{
                int i = Int32.Parse(pictureIndex.Value);
                i++;
                pictureIndex.Value = i.ToString();
            }
            showImage(Int32.Parse(pictureIndex.Value));
        }
    }
}