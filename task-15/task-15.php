<!-- code to connect html with php-->
<!-- By: M.Taleb-->
<!DOCTYPE html>
<html>
<head>
<style>

.for_rev{
text-align: center;
background-color:red;
}
#right{
text-align:right;
float:right;
width: 50%
}
#left{
text-align: left;
float:left;
width: 50%
}
#stop{
float:center;
text-align: center;
border-radius: 60%
}

</style>
</head>
<body>
<form action='conf/task-15.php' method='POST' target="_blank">

<div style="border:solid 5px;width:400px;margin: 0 auto;background-color:blue;height:auto">

<div class="for_rev">
<button type="submit" name="F">Forward</button>
</div>

<br> </br>
<br> </br>

<div id="right" >
<button type="submit" name="R">Right</button>
</div>

<div id="left">
<button type="submit" name="L">Left</button>
</div>

<div id="stop">
<button  id="stop" type="submit" name="S">Stop</button>
</div>

<div class="for_rev" style="margin-top:80px;">
<button type="submit" name="RV">Reverse</button>
</div>

</div>

</form>
</body>
</html>




