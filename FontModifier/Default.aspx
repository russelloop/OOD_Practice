<%@ Page Language="C#" Inherits="FontModifier.Default" %>
<!DOCTYPE html>
<html>
    <head runat="server">
	    <title>Default</title>
        <link rel="stylesheet" href="SeterCss.css" type="text/css" />
    </head>
    <body>
	    <form id="form1" runat="server">
                <asp:Label id="ShowText" runat="server" CssClass="testText">Example Example Example</asp:Label>
                <br />
                <p>Color Select:</p>
                <asp:RadioButton id="RadioButton1" runat="server" Text="Green" AutoPostBack="true" OnCheckedChanged="RBChanged1" />
                <asp:RadioButtonList id="RadioButtonList" runat="server" AutoPostBack="true" OnSelectedIndexChanged="RBLChanged1">
                    <asp:ListItem id="red" Text="Red"  Value="1" runat="server"/> 
                    <asp:ListItem id="blue" Text="Blue" Value="2" runat="server" />
                    <asp:ListItem id="yellow" Text="Yellow" Value="3" runat="server" />
                </asp:RadioButtonList>
                <p>Regular Style Select:</p>
                <asp:CheckBox id="CheckBox1" runat="server" Text="UnderLine" AutoPostBack="true" OnCheckedChanged="CBChanged1" />
                <asp:CheckBox id="CheckBox2" runat="server" Text="Bold" AutoPostBack="true" OnCheckedChanged="CBChanged2" />
                <asp:CheckBox id="CheckBox3" runat="server" Text="Italic" AutoPostBack="true" OnCheckedChanged="CBChanged3" />
	    </form>
    </body>
</html>
