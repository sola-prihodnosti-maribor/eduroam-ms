eduroam-ms
==========

Extension for Microsoft NPS adding attributes for compatibility with eduroam.si.

## Prerequisites

* Microsoft Windows Server 2008 R2 _or_ Microsoft Windows Server 2012
* Microsoft NPS

## Usage

1. Copy DLL into C:\Windows\System32 (or any other folder in your PATH).
2. Add a new entry "AuthorizationDLLs" of type REG_MULTI_SZ into HKLM\SYSTEM\CurrentControlSet\services\AuthSrv\Parameters.
3. Set or update value of "AuthorizationDLLs" to FILENAME.dll (replace filename with the name of your compiled DLL).

## Donations

<form action="https://www.paypal.com/cgi-bin/webscr" method="post">
<input type="hidden" name="cmd" value="_s-xclick">
<input type="hidden" name="hosted_button_id" value="R8NUTFXR7JSNQ">
<input type="image" src="https://www.paypalobjects.com/en_US/i/btn/btn_donate_LG.gif" border="0" name="submit" alt="PayPal - The safer, easier way to pay online!">
<img alt="" border="0" src="https://www.paypalobjects.com/en_US/i/scr/pixel.gif" width="1" height="1">
</form>
