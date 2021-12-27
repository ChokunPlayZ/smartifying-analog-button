const char indexpage[] = R"=====(
<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Button Basher</title>
</head>

<body>
    <div class="content">
        <h2>Button Basher</h2><br>
        <button onclick="trigger()">Toggle</button>
    </div>
</body>
<script>
    function trigger() {
        fetch('/t')
            .then(response => response.json())
            .then(data => console.log(data));
    }
</script>
<style>
    body {
        background-color: aqua;
        color: black;
        display: flex;
        align-items: center;
        justify-content: center;
    }
</style>

</html>
)=====";