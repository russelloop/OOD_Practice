<%@ Page Language="C#" Inherits="ListBox.Default" %>
<!DOCTYPE html>
<html>
<head runat="server">
	<title>ListBox</title>
    <link rel="stylesheet" href="ListBox.css" type="text/css" />
</head>
<body>
	<form id="form1" runat="server">
        <div class="listgroup">
            <asp:ListBox id="drop1" runat="server" CssClass="drop">
                <asp:ListItem selected="true" Text="Item 1" Value="1" Style="width=200px; height=300px"></asp:ListItem>
                <asp:ListItem Text="Item 2" Value="2"></asp:ListItem>
                <asp:ListItem Text="Item 3" Value="3"></asp:ListItem>
                <asp:ListItem Text="Item 4" Value="4"></asp:ListItem>
                <asp:ListItem Text="Item 5" Value="5"></asp:ListItem>
                <asp:ListItem Text="Item 6" Value="6"></asp:ListItem>
            </asp:ListBox>
            <asp:Button Text="Add" OnClick="AddItem" runat="server" CssClass="ADButton" />
            <asp:Button Text="Remove" OnClick="RemoveItem" runat="server" CssClass="RMButton"/>
            <asp:ListBox id="drop2" runat="server" CssClass="drop">
                <asp:ListItem Text="Item 7" Value="7"></asp:ListItem>
                <asp:ListItem Text="Item 8" Value="8"></asp:ListItem>
            </asp:ListBox>
        </div>
    </form>
</body>
</html>
