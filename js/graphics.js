const moveSpeed = 3.0;
const turnSpeed = 0.05;
const mouseTurnSpeed = 0.1;
const lineSize = 2.5;
const reactionTime = 0.0025;

const cursor = 
{
	x: window.innerWidth / 2,
	y: window.innerHeight / 2,
	pressed: false
};

class line
{
	constructor(cx, cy, dx, dy)
	{
		this.cx = centerWidth();
		this.cy = centerHeight();
		this.dx = 1;
		this.dy = -1;
		this.moveSpeed = 1.0;
		this.turnSpeed = 1.0;
		this.size = 1.0;
		this.mouseStrength = 0.0;
		this.turnStrength = 0.0;
	}

	move()
	{
		this.cx += this.dx * moveSpeed * this.moveSpeed;
		this.cy += this.dy * moveSpeed * this.moveSpeed;

		if (this.cx >= window.innerWidth)
		{
			this.dx = -Math.abs(this.dx); 
			this.cx = window.innerWidth;
		}
		if (this.cx <= 0)
		{
			this.dx = Math.abs(this.dx); 
			this.cx = 0;
		}
		if (this.cy >= window.innerHeight)
		{
			this.dy = -Math.abs(this.dy); 
			this.cy = window.innerHeight;
		}
		if (this.cy <= 0)
		{
			this.dy = Math.abs(this.dy); 
			this.cy = 0;
		}

		let cdx;
		let cdy;

		if (cursor.pressed)
		{
			this.mouseStrength = clamp(this.mouseStrength + reactionTime * this.turnSpeed, 0.0, 1.0);
			this.turnStrength = clamp(this.turnStrength - reactionTime * this.turnSpeed, 0.0, 1.0);

			cdx = cursor.x - this.cx;
			cdy = cursor.y - this.cy;

			this.dx += normalize(cdx, cdy) * mouseTurnSpeed * this.turnSpeed * this.mouseStrength;
			this.dy += normalize(cdy, cdx) * mouseTurnSpeed * this.turnSpeed * this.mouseStrength;
		}
		else
		{
			this.mouseStrength = clamp(this.mouseStrength - reactionTime * this.turnSpeed, 0.0, 1.0);
			this.turnStrength = clamp(this.turnStrength + reactionTime * this.turnSpeed, 0.0, 1.0);

			cdx = random11();
			cdy = random11();

			this.dx += normalize(cdx, cdy) * turnSpeed * this.turnSpeed * this.turnStrength;
			this.dy += normalize(cdy, cdx) * turnSpeed * this.turnSpeed * this.turnStrength;
		}

		/*this.dx = clamp(this.dx, -1.0, 1.0);
		this.dy = clamp(this.dy, -1.0, 1.0);*/
		let tempx = this.dx;
		let tempy = this.dy;
		this.dx = normalize(tempx, tempy);
		this.dy = normalize(tempy, tempx);
	}
};

const lines = [];

const canvas = document.createElement("canvas");
canvas.setAttribute("width", window.innerWidth);
canvas.setAttribute("height", window.innerHeight);
canvas.classList.add("visible");
canvas.classList.add("instant");
document.body.append(canvas);

let cx = centerWidth();
let cy = centerHeight();

let dx = 1;
let dy = -1;

const ctx = canvas.getContext("2d");
ctx.lineWidth = 5;
ctx.strokeStyle ="rgb(13, 110, 253, 0.1)";
ctx.globalAlpha = 1.0;

setup(5000);

/*setInterval(frame, 1);*/

function centerWidth()
{
	return (window.innerWidth * 0.5);
}

function centerHeight()
{
	return (window.innerHeight * 0.5);
}

function random11()
{
	return ((Math.random() - 0.5) * 2.0);
}

function clamp(val, min, max)
{
	if (val < min) return (min);
	if (val > max) return (max);
	return (val);
}

function normalize(a, b)
{
	return (a / (Math.abs(a) + Math.abs(b)));
}

function setup(amount)
{

	for (let i = 0; i < amount; i++)
	{
		lines[i] = new line();
		lines[i].dx = random11();
		lines[i].dy = random11();
		lines[i].moveSpeed = 1.0 + (random11() * 0.5);
		lines[i].turnSpeed = 1.0 + (random11() * 0.5);
		lines[i].size = 1.0 + (random11() * 0.5);
	}
}

function moveLine(i)
{
	ctx.lineWidth = lineSize * lines[i].size;
	ctx.beginPath();
	ctx.moveTo(lines[i].cx, lines[i].cy);

	lines[i].move();

	ctx.lineTo(lines[i].cx, lines[i].cy);
	ctx.stroke();
	ctx.closePath();
}

addEventListener("mousedown", (e) => 
{
	cursor.pressed = true;
});

addEventListener("mouseup", (e) => 
{
	cursor.pressed = false;
});

addEventListener("mousemove", (e) => 
{
	cursor.x = e.clientX;
	cursor.y = e.clientY;
});

function frame()
{
	requestAnimationFrame(frame);
	/*ctx.fillStyle = '"' + document.body.style.getPropertyValue(document.body.style.
		getPropertyValue('--secondary-tint-color')) + '"';*/
	ctx.fillStyle = 'rgba(0, 0, 0, 0.01)';
  	ctx.fillRect(0, 0, window.innerWidth, window.innerHeight);

	for (let i = 0; i < lines.length; i++)
	{
		moveLine(i);
	}
}

frame();