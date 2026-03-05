function Component()
{
}

Component.prototype.createOperations = function()
{
    component.createOperations();

    var appMenuPath = "@HomeDir@/.local/share/applications/FultimaItemGen.desktop";
    var desktopPath = "@HomeDir@/Desktop/FultimaItemGen.desktop"; 
    var desktopContent = "Version=1.0\n" +
                         "Type=Application\n" +
                         "Terminal=false\n" +
                         "Exec=\"@TargetDir@/fultima-gen\"\n" +
                         "Name=Fabula Ultima Item Generator\n" +
                         "Icon=@TargetDir@/icon.png\n" +
                         "Path=@TargetDir@";

    component.addOperation("CreateDesktopEntry", appMenuPath, desktopContent);

    component.addOperation("CreateDesktopEntry", desktopPath, desktopContent);
}