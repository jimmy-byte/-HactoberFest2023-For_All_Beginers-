# responsive-footer
Having a mobile responsive footer is essential in the mobile age and this article will walk you through adding a responsive footer to your website.

## Tutorial

For detailed instructions, view Solodev's [Adding a Responsive Footer to your Website](https://www.solodev.com/blog/web-design/adding-a-responsive-footer-to-your-website.stml) article.

## Demo

Check out a working example on [JSFiddle](https://jsfiddle.net/solodev/6spd9xku/).

## HTML

The responsive footer contains the following basic HTML markup.

```
<footer class="ct-footer">
                <div class="container">
                    <form name="contentForm" enctype="multipart/form-data" method="post" action="">
                        <div class="ct-footer-pre text-center-lg">
                            <div class="inner">
                                <span>Join WebCorpCo to receive updates, news &amp; events!</span>
                            </div>
                            <div class="inner">
                                <div class="form-group">
                                    <input name="formfields[nl_email]" id="nl_email" class="validate[required]" placeholder="Enter your email address" type="text" value=""> <label for="nl_email" class="sr-only">Email Address</label> <button type="submit" class="btn btn-motive">Join</button>
                                </div>
                            </div>
                        </div>
                    </form>
                    <ul class="ct-footer-list text-center-sm">
                        <li>
                            <h2 class="ct-footer-list-header">
                                Learn More
                            </h2>
                            <ul>
                                <li>
                                    <a href="">Company</a>
                                </li>
                                <li>
                                    <a href="">Clients</a>
                                </li>
                                <li>
                                    <a href="">News</a>
                                </li>
                                <li>
                                    <a href="">Careers</a>
                                </li>
                            </ul>
                        </li>
                        <li>
                            <h2 class="ct-footer-list-header">
                                Services
                            </h2>
                            <ul>
                                <li>
                                    <a href="">Design</a>
                                </li>
                                <li>
                                    <a href="">Marketing</a>
                                </li>
                                <li>
                                    <a href="">Sales</a>
                                </li>
                                <li>
                                    <a href="">Programming</a>
                                </li>
                                <li>
                                    <a href="">Support</a>
                                </li>
                            </ul>
                        </li>
                        <li>
                            <h2 class="ct-footer-list-header">
                                The Industry
                            </h2>
                            <ul>
                                <li>
                                    <a href="">Thought Leadership</a>
                                </li>
                                <li>
                                    <a href="">Webinars</a>
                                </li>
                                <li>
                                    <a href="">Events</a>
                                </li>
                                <li>
                                    <a href="">Sponsorships</a>
                                </li>
                                <li>
                                    <a href="">Advisors</a>
                                </li>
                                <li>
                                    <a href="">Training Program</a>
                                </li>
                                <li>
                                    <a href="">Activities &amp; Campaigns</a>
                                </li>
                            </ul>
                        </li>
                        <li>
                            <h2 class="ct-footer-list-header">
                                Public Relations
                            </h2>
                            <ul>
                                <li>
                                    <a href="">WebCorpCo Blog</a>
                                </li>
                                <li>
                                    <a href="">Hackathons</a>
                                </li>
                                <li>
                                    <a href="">Videos</a>
                                </li>
                                <li>
                                    <a href="">News Releases</a>
                                </li>
                                <li>
                                    <a href="">Newsletters</a>
                                </li>
                            </ul>
                        </li>
                        <li>
                            <h2 class="ct-footer-list-header">
                                About
                            </h2>
                            <ul>
                                <li>
                                    <a href="">FAQ</a>
                                </li>
                                <li>
                                    <a href="">Our Board</a>
                                </li>
                                <li>
                                    <a href="">Our Staff</a>
                                </li>
                                <li>
                                    <a href="">Contact Us</a>
                                </li>
                            </ul>
                        </li>
                    </ul>
                    <div class="ct-footer-meta text-center-sm">
                        <div class="row">
                            <div class="col-sm-6 col-md-2">
                                <img alt="logo" src="https://www.solodev.com/assets/footer/logo.png">
                            </div>
                            <div class="col-sm-6 col-md-3">
                                <address>
                                    <span>WebCorpCo<br></span>123 Easy Street<br>
                                    Orlando, Florida, 32801<br>
                                    <span>Phone: <a href="tel:5555555555">(555) 555-8899</a></span>
                                </address>
                            </div>
                            <div class="col-sm-6 col-md-2 ct-u-paddingTop10">
                                <a href="" target="_blank"><img alt="app store" src="https://www.solodev.com/assets/footer/appstore.png"></a>
                            </div>
                            <div class="col-sm-6 col-md-2 ct-u-paddingTop10">
                                <a href="" target="_blank"><img alt="google play store" src="https://www.solodev.com/assets/footer/androidstore.png"></a>
                            </div>
                            <div class="col-sm-6 col-md-3">
                                <ul class="ct-socials list-unstyled list-inline">
                                    <li>
                                        <a href="" target="_blank"><img alt="facebook" src="https://www.solodev.com/assets/footer/facebook-white.png"></a>
                                    </li>
                                    <li>
                                        <a href="" target="_blank"><img alt="twitter" src="https://www.solodev.com/assets/footer/twitter-white.png"></a>
                                    </li>
                                    <li>
                                        <a href="" target="_blank"><img alt="youtube" src="https://www.solodev.com/assets/footer/youtube-white.png"></a>
                                    </li>
                                    <li>
                                        <a href="" target="_blank"><img alt="instagram" src="https://www.solodev.com/assets/footer/instagram-white.png"></a>
                                    </li>
                                    <li>
                                        <a href="" target="_blank"><img alt="pinterest" src="https://www.solodev.com/assets/footer/pinterest-white.png"></a>
                                    </li>
                                </ul>
                            </div>
                        </div>
                    </div>
                </div>
                <div class="ct-footer-post">
                    <div class="container">
                        <div class="inner-left">
                            <ul>
                                <li>
                                    <a href="">FAQ</a>
                                </li>
                                <li>
                                    <a href="">News</a>
                                </li>
                                <li>
                                    <a href="">Contact Us</a>
                                </li>
                            </ul>
                        </div>
                        <div class="inner-right">
                            <p>
                                Copyright © 2016 WebCorpCo.&nbsp;<a href="">Privacy Policy</a>
                            </p>
                            <p>
                                <a class="ct-u-motive-color" href="" target="_blank">Web Design</a> by DigitalUs on <a href="" target="_blank">Solodev CMS</a>
                            </p>
                        </div>
                    </div>
                </div>
            </footer>
```

## CSS

All necessary CSS is in footer.css

## External Includes

```
<link href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.6/css/bootstrap.min.css" rel="stylesheet">
<link rel="stylesheet" href="footer.css">

<script src="https://ajax.googleapis.com/ajax/libs/jquery/1.12.4/jquery.min.js"></script>
<script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.6/js/bootstrap.min.js"></script>
```
