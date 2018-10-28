<%@ Page Language="C#" Inherits="simpleCaculator.Default" %>
<!DOCTYPE html>
<html>
<head runat="server">
	<title>Calculator</title>
    <link rel="stylesheet" href="calCss.css" type="text/css" />
</head>
    <body>
        <form id="form1" runat="server" class="calculator">
            <div class="top">
                <asp:TextBox CssClass="screen" ID="txtResult" runat="server" Text=""></asp:TextBox>
                <asp:Button CssClass="btn1 clear" ID="btnClear" runat="server" Text="C" OnClick="buttonClearClick"/>
            </div>
            <div class="keys">
                <div class="row">
                    <asp:Button CssClass="btn1" ID="Button7" runat="server" Text="7" OnClick="buttonNumClick"/>
                    <asp:Button CssClass="btn1" ID="Button8" runat="server" Text="8" OnClick="buttonNumClick"/>
                    <asp:Button CssClass="btn1" ID="Button9" runat="server" Text="9" OnClick="buttonNumClick"/>
                    <asp:Button CssClass="btn1 operator" ID="btnAdd" runat="server" Text="+" OnClick="buttonOperatorClick"/>
                </div>
                <div class="row">
                    <asp:Button CssClass="btn1" ID="Button4" runat="server" Text="4" OnClick="buttonNumClick"/>
                    <asp:Button CssClass="btn1" ID="Button5" runat="server" Text="5" OnClick="buttonNumClick"/>
                    <asp:Button CssClass="btn1" ID="Button6" runat="server" Text="6" OnClick="buttonNumClick"/>
                    <asp:Button CssClass="btn1 operator" ID="btnSub" runat="server" Text="-" OnClick="buttonOperatorClick"/>
                </div>
                <div class="row">
                    <asp:Button CssClass="btn1" ID="Button1" runat="server" Text="1" OnClick="buttonNumClick"/>
                    <asp:Button CssClass="btn1" ID="Button2" runat="server" Text="2" OnClick="buttonNumClick"/>
                    <asp:Button CssClass="btn1" ID="Button3" runat="server" Text="3" OnClick="buttonNumClick"/>
                    <asp:Button CssClass="btn1 operator" ID="btnDiv" runat="server" Text="/" OnClick="buttonOperatorClick"/>
                </div>
                <div class="row">
                     <asp:Button CssClass="btn1" ID="Button0" runat="server" Text="0" OnClick="buttonNumClick"/>
                    <asp:Button CssClass="btn1" ID="btnPoint" runat="server" Text="." OnClick="buttonDecimalClick"/>
                    <asp:Button CssClass="btn1 equal" ID="btnequ" runat="server" Text="=" OnClick="buttonEqualsClick"/>
                    <asp:Button CssClass="btn1 operator" ID="btnMul" runat="server" Text="*" OnClick="buttonOperatorClick"/>
                </div>
            </div>
	    </form>
    </body>
</html>
