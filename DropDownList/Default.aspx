<%@ Page Language="C#" Inherits="DropDownList.Default" %>
<!DOCTYPE html>
<html>
<head runat="server">
	<title>Default</title>
</head>
    <body>
	    <form id="form1" runat="server">
		    <div>
                <asp:DropDownList id="DDList1" runat="server" AutoPostBack="true">
                    <asp:ListItem Selected="true" Value="1">Email System</asp:ListItem>
                    <asp:ListItem Value="2">Search Engine</asp:ListItem>
                    <asp:ListItem Value="3">News Website</asp:ListItem>
                </asp:DropDownList>
                <asp:DropDownList id="DDList2" runat="server" AutoPostBack="true">
                    <asp:ListItem Value="1">https://outlook.live.com/owa</asp:ListItem>
                    <asp:ListItem Value="2">https://login.yahoo.com</asp:ListItem>
                    <asp:ListItem Value="3">https://mail.google.com</asp:ListItem>
                </asp:DropDownList>
            </div>
	    </form>
    </body>
</html>
