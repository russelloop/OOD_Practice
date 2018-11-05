<%@ Page Language="C#" Inherits="ImageSalon.Default" %>
<!DOCTYPE html>
<html>
    <head runat="server">
	    <title>ImageSalon</title>
        <link rel="stylesheet" href="BoxCss.css" type="text/css" />
    </head>
    <body>
	    <form id="form1" runat="server">
            <div>
                <asp:image runat="server" ID="Image" style="width:480px; height:370px; margin-bottom:10px;" ></asp:image>
                <br/>
                <asp:Button ID="LastPicButton" runat="server" Text="Last" 
            onclick="LastPicButton_Click" CssClass="button"/>&nbsp;&nbsp;&nbsp;&nbsp; 
                <asp:Button ID="NextPicButton" runat="server" Text="Next" 
            onclick="NextPicButton_Click" CssClass="button"/>
                <asp:HiddenField ID="pictureIndex" Value="0" runat="server" />
            </div>
	    </form>
    </body>
</html>
